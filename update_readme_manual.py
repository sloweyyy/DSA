#!/usr/bin/env python3
"""
Manual README Update Script

This script allows you to manually update your README with the latest LeetCode solution.
Usage:
    python update_readme_manual.py [filename] [leetcode_url]
    
Examples:
    python update_readme_manual.py "02099. Find Subsequence of Length K With the Largest Sum.go"
    python update_readme_manual.py "02099. Find Subsequence of Length K With the Largest Sum.go" "https://leetcode.com/problems/longest-subsequence-repeated-k-times"
"""

import os
import re
import json
import sys
import subprocess
from datetime import datetime


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


def generate_leetcode_url(problem_num, title):
    """Generate LeetCode URL from problem number and title."""
    # Convert title to URL-friendly format
    url_title = re.sub(r'[^\w\s-]', '', title.lower())
    url_title = re.sub(r'[-\s]+', '-', url_title).strip('-')
    
    return f"https://leetcode.com/problems/{url_title}"


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
        return "latest"


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


def add_new_solution(filepath, leetcode_url=None):
    """Add a new solution to the list."""
    problem_num, title, extension = extract_problem_info(filepath)
    
    if not problem_num or not title or not extension:
        print(f"Error: Could not parse filename '{filepath}'")
        print("Expected format: '02099. Problem Title.extension'")
        return False
    
    # Generate URL if not provided
    if not leetcode_url:
        leetcode_url = generate_leetcode_url(problem_num, title)
    
    # Create solution info
    solution_info = {
        'problem_num': problem_num,
        'title': title,
        'filepath': filepath,
        'leetcode_url': leetcode_url,
        'language': get_language_display_name(extension),
        'commit_hash': get_latest_commit_hash(),
        'timestamp': datetime.now().isoformat()
    }
    
    # Load existing solutions
    existing_solutions = load_existing_solutions()
    
    # Remove any existing solution with the same problem number
    existing_solutions = [s for s in existing_solutions if s['problem_num'] != problem_num]
    
    # Add new solution at the beginning
    all_solutions = [solution_info] + existing_solutions
    
    # Keep only the latest 10 solutions
    latest_solutions = all_solutions[:10]
    
    # Save updated solutions
    save_solutions(latest_solutions)
    
    print(f"✅ Added solution: {problem_num}. {title} ({get_language_display_name(extension)})")
    print(f"🔗 LeetCode URL: {leetcode_url}")
    
    return True


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


def update_readme_with_latest():
    """Update README with the latest solutions."""
    solutions = load_existing_solutions()
    latest_section = generate_latest_solutions_section(solutions)
    
    # Save the section to a file for other scripts to use
    with open('latest_solutions_section.txt', 'w') as f:
        f.write(latest_section)
    
    print("📝 Updated latest solutions section")
    print("💡 Run 'python update_readme_with_solutions.py' to update the full README")


def main():
    if len(sys.argv) < 2:
        print("Usage: python update_readme_manual.py <filename> [leetcode_url]")
        print("\nExamples:")
        print('  python update_readme_manual.py "02099. Find Subsequence of Length K With the Largest Sum.go"')
        print('  python update_readme_manual.py "02099. Problem Title.go" "https://leetcode.com/problems/actual-url"')
        return
    
    filename = sys.argv[1]
    leetcode_url = sys.argv[2] if len(sys.argv) > 2 else None
    
    # Check if file exists
    if not os.path.exists(filename):
        print(f"❌ Error: File '{filename}' not found")
        return
    
    # Add the solution
    if add_new_solution(filename, leetcode_url):
        update_readme_with_latest()
        print("\n🎉 README update completed!")
        print("📋 Latest solutions have been updated in the JSON file")
    else:
        print("❌ Failed to add solution")


if __name__ == "__main__":
    main()
