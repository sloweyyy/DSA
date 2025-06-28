#!/usr/bin/env python3
import os
import re
import json
import subprocess
import sys
from datetime import datetime
from urllib.parse import quote


def get_git_diff_files():
    """Get list of added/modified files from the last commit."""
    try:
        # Get files changed in the last commit
        result = subprocess.run(
            ['git', 'diff', '--name-status', 'HEAD~1', 'HEAD'],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=True
        )
        
        files = []
        for line in result.stdout.strip().split('\n'):
            if line:
                status, filepath = line.split('\t', 1)
                # Only include added (A) or modified (M) files
                if status in ['A', 'M']:
                    files.append(filepath)
        
        return files
    except subprocess.CalledProcessError as e:
        print(f"Error getting git diff: {e}")
        return []


def extract_problem_info(filename):
    """Extract problem number and title from filename."""
    # Pattern: "02099. Find Subsequence of Length K With the Largest Sum.go"
    pattern = r'^(\d{5})\.\s*(.+?)\.([a-zA-Z0-9]+)$'
    match = re.match(pattern, os.path.basename(filename))
    
    if match:
        problem_num = match.group(1)
        title = match.group(2).strip()
        extension = match.group(3)
        return problem_num, title, extension
    
    return None, None, None


def generate_leetcode_url(problem_num, title):
    """Generate LeetCode URL from problem number and title."""
    # Convert title to URL-friendly format
    # Remove special characters and convert to lowercase with hyphens
    url_title = re.sub(r'[^\w\s-]', '', title.lower())
    url_title = re.sub(r'[-\s]+', '-', url_title).strip('-')
    
    # Remove leading zeros from problem number
    problem_num_int = int(problem_num)
    
    return f"https://leetcode.com/problems/{url_title}"


def get_language_display_name(extension):
    """Get display name for programming language."""
    lang_map = {
        'py': 'Python',
        'js': 'JavaScript',
        'ts': 'TypeScript',
        'java': 'Java',
        'cpp': 'C++',
        'c': 'C',
        'cs': 'C#',
        'go': 'Go',
        'rs': 'Rust',
        'php': 'PHP',
        'rb': 'Ruby',
        'dart': 'Dart',
        'kt': 'Kotlin',
        'swift': 'Swift'
    }
    return lang_map.get(extension.lower(), extension.upper())


def get_latest_commit_hash():
    """Get the latest commit hash."""
    try:
        result = subprocess.run(
            ['git', 'rev-parse', 'HEAD'],
            stdout=subprocess.PIPE,
            text=True,
            check=True
        )
        return result.stdout.strip()[:7]  # Short hash
    except subprocess.CalledProcessError:
        return "unknown"


def process_leetcode_files():
    """Process LeetCode solution files and extract information."""
    changed_files = get_git_diff_files()
    leetcode_solutions = []
    
    # Filter for LeetCode files
    leetcode_dirs = ['LeetCode Daily', 'Weekly Contest']
    
    for filepath in changed_files:
        # Check if file is in LeetCode directories
        if any(filepath.startswith(dir_name) for dir_name in leetcode_dirs):
            problem_num, title, extension = extract_problem_info(filepath)
            
            if problem_num and title and extension:
                leetcode_url = generate_leetcode_url(problem_num, title)
                language = get_language_display_name(extension)
                commit_hash = get_latest_commit_hash()
                
                solution_info = {
                    'problem_num': problem_num,
                    'title': title,
                    'filepath': filepath,
                    'leetcode_url': leetcode_url,
                    'language': language,
                    'commit_hash': commit_hash,
                    'timestamp': datetime.now().isoformat()
                }
                
                leetcode_solutions.append(solution_info)
    
    return leetcode_solutions


def load_existing_solutions():
    """Load existing solutions from JSON file."""
    solutions_file = 'latest_solutions.json'
    if os.path.exists(solutions_file):
        try:
            with open(solutions_file, 'r') as f:
                return json.load(f)
        except (json.JSONDecodeError, IOError):
            return []
    return []


def save_solutions(solutions):
    """Save solutions to JSON file."""
    solutions_file = 'latest_solutions.json'
    with open(solutions_file, 'w') as f:
        json.dump(solutions, f, indent=2)


def update_solutions_list(new_solutions):
    """Update the solutions list, keeping only the latest 10."""
    existing_solutions = load_existing_solutions()
    
    # Add new solutions to the beginning
    all_solutions = new_solutions + existing_solutions
    
    # Remove duplicates (same problem number), keeping the newest
    seen_problems = set()
    unique_solutions = []
    
    for solution in all_solutions:
        problem_key = solution['problem_num']
        if problem_key not in seen_problems:
            seen_problems.add(problem_key)
            unique_solutions.append(solution)
    
    # Keep only the latest 10 solutions
    latest_solutions = unique_solutions[:10]
    
    save_solutions(latest_solutions)
    return latest_solutions


def generate_latest_solutions_section(solutions):
    """Generate the Latest Solutions section for README."""
    if not solutions:
        return "No recent solutions found."
    
    section = "| Problem | Solution | Language | Commit |\n"
    section += "|---------|----------|----------|--------|\n"
    
    for solution in solutions:
        problem_link = f"[{solution['title']}]({solution['leetcode_url']})"
        solution_link = f"[View Solution]({solution['filepath']})"
        commit_link = f"[{solution['commit_hash']}](https://github.com/sloweyyy/DSA/commit/{get_full_commit_hash()})"
        
        section += f"| {problem_link} | {solution_link} | {solution['language']} | {commit_link} |\n"
    
    return section


def get_full_commit_hash():
    """Get the full commit hash."""
    try:
        result = subprocess.run(
            ['git', 'rev-parse', 'HEAD'],
            stdout=subprocess.PIPE,
            text=True,
            check=True
        )
        return result.stdout.strip()
    except subprocess.CalledProcessError:
        return "unknown"


if __name__ == "__main__":
    print("Processing LeetCode solutions...")
    
    # Get new solutions from the latest commit
    new_solutions = process_leetcode_files()
    
    if new_solutions:
        print(f"Found {len(new_solutions)} new/updated LeetCode solutions:")
        for solution in new_solutions:
            print(f"  - {solution['problem_num']}: {solution['title']} ({solution['language']})")
        
        # Update the solutions list
        latest_solutions = update_solutions_list(new_solutions)
        
        # Generate the section for README
        latest_section = generate_latest_solutions_section(latest_solutions)
        
        # Save the section to a file for the workflow to use
        with open('latest_solutions_section.txt', 'w') as f:
            f.write(latest_section)
        
        print("Latest solutions section generated successfully!")
    else:
        print("No new LeetCode solutions found in the latest commit.")
        
        # Still generate section from existing solutions
        existing_solutions = load_existing_solutions()
        latest_section = generate_latest_solutions_section(existing_solutions)
        
        with open('latest_solutions_section.txt', 'w') as f:
            f.write(latest_section)
