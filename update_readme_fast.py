#!/usr/bin/env python3
"""
Fast README updater that combines solution processing and README generation.
This script is optimized for speed by avoiding external dependencies and 
combining multiple operations into a single process.
"""

import os
import re
import json
import subprocess
from datetime import datetime
from urllib.parse import quote


def get_git_diff_files():
    """Get list of files changed in the latest commit."""
    try:
        result = subprocess.run(
            ['git', 'diff', '--name-only', 'HEAD~1', 'HEAD'],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=True
        )
        return result.stdout.strip().split('\n') if result.stdout.strip() else []
    except subprocess.CalledProcessError:
        print("Error getting git diff. Using all files.")
        return []


def extract_leetcode_info(filename):
    """Extract LeetCode problem information from filename."""
    # Pattern: number. title.extension
    pattern = r'^(\d+)\.\s*(.+)\.(py|js|ts|java|cpp|cs|go|php|dart|hack)$'
    match = re.match(pattern, filename)
    
    if match:
        problem_number = match.group(1)
        title = match.group(2).strip()
        language_ext = match.group(3)
        
        # Map file extensions to language names
        language_map = {
            'py': 'Python', 'js': 'JavaScript', 'ts': 'TypeScript',
            'java': 'Java', 'cpp': 'C++', 'cs': 'C#', 'go': 'Go',
            'php': 'PHP', 'dart': 'Dart', 'hack': 'Hack'
        }
        
        language = language_map.get(language_ext, language_ext.upper())
        
        # Generate LeetCode URL
        url_title = title.lower()
        url_title = re.sub(r'[^\w\s-]', '', url_title)
        url_title = re.sub(r'[-\s]+', '-', url_title)
        leetcode_url = f"https://leetcode.com/problems/{url_title}"
        
        return {
            'problem_number': problem_number,
            'title': title,
            'language': language,
            'leetcode_url': leetcode_url,
            'filepath': None  # Will be set by caller
        }
    
    return None


def get_commit_hash():
    """Get the current commit hash."""
    try:
        result = subprocess.run(
            ['git', 'rev-parse', '--short', 'HEAD'],
            stdout=subprocess.PIPE,
            text=True,
            check=True
        )
        return result.stdout.strip()
    except subprocess.CalledProcessError:
        return "unknown"


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


def load_existing_solutions():
    """Load existing solutions from JSON file."""
    if os.path.exists('latest_solutions.json'):
        try:
            with open('latest_solutions.json', 'r') as f:
                return json.load(f)
        except (json.JSONDecodeError, FileNotFoundError):
            return []
    return []


def save_solutions(solutions):
    """Save solutions to JSON file."""
    with open('latest_solutions.json', 'w') as f:
        json.dump(solutions, f, indent=2)


def update_solutions_list(new_solutions):
    """Update the solutions list with new solutions."""
    existing_solutions = load_existing_solutions()

    # Normalize existing solutions to use consistent field names
    normalized_existing = []
    for sol in existing_solutions:
        # Handle both old format (problem_num) and new format (problem_number)
        problem_number = sol.get('problem_number') or sol.get('problem_num', '')
        normalized_sol = {
            'problem_number': problem_number,
            'title': sol.get('title', ''),
            'language': sol.get('language', ''),
            'leetcode_url': sol.get('leetcode_url', ''),
            'filepath': sol.get('filepath', ''),
            'commit_hash': sol.get('commit_hash', '')
        }
        normalized_existing.append(normalized_sol)

    # Create a set of existing solution identifiers
    existing_ids = {(sol['problem_number'], sol['language']) for sol in normalized_existing}

    # Add new solutions that don't already exist
    for solution in new_solutions:
        solution_id = (solution['problem_number'], solution['language'])
        if solution_id not in existing_ids:
            normalized_existing.append(solution)

    # Keep only the latest 10 solutions
    latest_solutions = normalized_existing[-10:]

    save_solutions(latest_solutions)
    return latest_solutions


def get_language_stats():
    """Get language statistics by analyzing file extensions."""
    language_extensions = {
        '.py': 'Python',
        '.js': 'JavaScript', 
        '.ts': 'TypeScript',
        '.java': 'Java',
        '.go': 'Go',
        '.cpp': 'C++',
        '.cs': 'C#',
        '.php': 'PHP',
        '.dart': 'Dart',
        '.hack': 'Hack'
    }
    
    language_counts = {}
    total_files = 0
    
    # Walk through LeetCode Daily and Weekly Contest directories
    for root, _, files in os.walk('.'):
        if 'LeetCode Daily' in root or 'Weekly Contest' in root:
            for file in files:
                total_files += 1
                _, ext = os.path.splitext(file)
                if ext in language_extensions:
                    lang = language_extensions[ext]
                    language_counts[lang] = language_counts.get(lang, 0) + 1
    
    # Convert counts to percentages
    language_stats = {}
    for lang, count in language_counts.items():
        percentage = (count / total_files) * 100 if total_files > 0 else 0
        language_stats[lang] = {'size': percentage}
    
    return language_stats


def generate_language_section(language_stats):
    """Generate language statistics section."""
    if not language_stats:
        return "No language statistics available."

    # Extract percentages directly since we're now calculating them in get_language_stats
    language_percentages = {}
    for language, data in language_stats.items():
        if isinstance(data, dict) and 'size' in data:
            language_percentages[language] = data['size']

    sorted_languages = sorted(language_percentages.items(),
                              key=lambda item: item[1], reverse=True)

    language_section = ""
    for language, percentage in sorted_languages:
        language_section += f"- {language}: {percentage:.2f}%\n"

    return language_section


def generate_latest_solutions_section(solutions):
    """Generate the Latest Solutions section for README."""
    if not solutions:
        return "No recent solutions found."
    
    section = "| Problem | Solution | Language | Commit |\n"
    section += "|---------|----------|----------|--------|\n"
    
    for solution in solutions:
        problem_link = f"[{solution['title']}]({solution['leetcode_url']})"
        # Format the solution link as a proper GitHub blob URL
        github_file_url = f"https://github.com/sloweyyy/DSA/blob/main/{solution['filepath'].replace(' ', '%20')}"
        solution_link = f"[View Solution]({github_file_url})"
        commit_link = f"[{solution['commit_hash']}](https://github.com/sloweyyy/DSA/commit/{get_full_commit_hash()})"
        
        section += f"| {problem_link} | {solution_link} | {solution['language']} | {commit_link} |\n"
    
    return section


def get_current_timestamp():
    """Get current timestamp for README footer."""
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S UTC")


def update_readme(language_section, latest_solutions_section):
    """Update README with both language stats and latest solutions."""
    readme_content = f"""
# LeetCode & Algorithmic Solutions

**Author:** SloWey  
**Email:** truonglevinhphuc2006@gmail.com

This repository documents my journey through Data Structures and Algorithms (DSA) by solving LeetCode problems. I'm using this as a way to improve my coding skills and prepare for technical interviews.

## 🚀 Latest Solutions

Here are my most recent LeetCode solutions:

{latest_solutions_section}

## 📊 Languages Used

Here's a breakdown of the languages I've been using, along with their contribution percentage:

{language_section}

## 📁 Contents

*   **Codeforce Contests:** Solutions from Codeforces competitions.
*   **Codeforce Problemset:** Solutions from specific problems on Codeforces.
*   **LeetCode Daily:** My solutions to daily LeetCode challenges.
*   **Weekly Contest:** Solutions from LeetCode Weekly Contests.

## 🚀 Getting Started

### Prerequisites

*   Ensure you have the necessary compilers or interpreters installed for the languages you want to explore.

### Usage

*   Feel free to browse the code and adapt it to your needs. Each file typically contains the solution to one specific problem.
*   Use these solutions as references for understanding algorithms and coding techniques.

## 🤝 Contributing

I welcome your contributions! If you'd like to contribute a solution or an improvement:

1.  Fork this repository.
2.  Create a new branch with a descriptive name for your changes.
3.  Implement your solution and provide clear comments and documentation.
4.  Test your code thoroughly.
5.  Open a pull request detailing your changes.

## 📄 License

This project is licensed under the [MIT License](LICENSE).

## 📧 Contact

Feel free to reach out via email at truonglevinhphuc2006@gmail.com for any questions, feedback, or suggestions.

---

*Last updated: {get_current_timestamp()}*"""

    with open('README.md', 'w') as f:
        f.write(readme_content)


def main():
    """Main function that processes solutions and updates README."""
    print("🔍 Processing LeetCode solutions...")
    
    # Get changed files
    changed_files = get_git_diff_files()
    
    # Filter for LeetCode solution files
    leetcode_files = []
    for file in changed_files:
        if ('LeetCode Daily' in file or 'Weekly Contest' in file) and not file.endswith('.md'):
            leetcode_files.append(file)
    
    new_solutions = []
    commit_hash = get_commit_hash()
    
    # Process new LeetCode files
    for filepath in leetcode_files:
        if os.path.exists(filepath):
            filename = os.path.basename(filepath)
            solution_info = extract_leetcode_info(filename)
            
            if solution_info:
                solution_info['filepath'] = filepath
                solution_info['commit_hash'] = commit_hash
                new_solutions.append(solution_info)
                print(f"✅ Found: {solution_info['title']} ({solution_info['language']})")
    
    if new_solutions:
        print(f"📝 Found {len(new_solutions)} new LeetCode solution(s)")
        latest_solutions = update_solutions_list(new_solutions)
    else:
        print("No new LeetCode solutions found in the latest commit.")
        latest_solutions = load_existing_solutions()
    
    # Generate language statistics
    print("📊 Calculating language statistics...")
    language_stats = get_language_stats()
    language_section = generate_language_section(language_stats)
    
    # Generate latest solutions section
    print("📝 Generating latest solutions section...")
    latest_solutions_section = generate_latest_solutions_section(latest_solutions)
    
    # Save the section to a file for the workflow to use
    with open('latest_solutions_section.txt', 'w') as f:
        f.write(latest_solutions_section)
    
    # Update README
    print("🔄 Updating README...")
    update_readme(language_section, latest_solutions_section)
    
    print("✅ README updated successfully!")


if __name__ == "__main__":
    main()
