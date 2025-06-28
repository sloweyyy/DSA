#!/usr/bin/env python3
import os
import json
import subprocess


def get_language_stats():
    """Get language statistics using github-linguist."""
    try:
        result = subprocess.run(
            ['github-linguist', '--json'], stdout=subprocess.PIPE, check=True)
        return json.loads(result.stdout)
    except subprocess.CalledProcessError as e:
        print(f"Error occurred while running github-linguist: {e}")
        return {}
    except FileNotFoundError:
        print("The github-linguist command is not found. Make sure it is installed and accessible.")
        return {}


def generate_language_section(language_stats):
    """Generate language statistics section."""
    if not language_stats:
        return "No language statistics available."

    total_bytes = 0
    language_bytes = {}

    for language, data in language_stats.items():
        if isinstance(data, dict) and 'size' in data:
            bytes_count = data['size']
            language_bytes[language] = bytes_count
            total_bytes += bytes_count

    sorted_languages = sorted(language_bytes.items(),
                              key=lambda item: item[1], reverse=True)

    language_section = ""
    for language, bytes_ in sorted_languages:
        percentage = (bytes_ / total_bytes) * 100 if total_bytes > 0 else 0
        language_section += f"- {language}: {percentage:.2f}%\n"

    return language_section


def load_latest_solutions_section():
    """Load the latest solutions section from file."""
    solutions_file = 'latest_solutions_section.txt'
    if os.path.exists(solutions_file):
        with open(solutions_file, 'r') as f:
            return f.read().strip()
    return "No recent solutions found."


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


def get_current_timestamp():
    """Get current timestamp for README footer."""
    from datetime import datetime
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S UTC")


if __name__ == "__main__":
    print("Updating README with language stats and latest solutions...")
    
    # Get language statistics
    language_stats = get_language_stats()
    language_section = generate_language_section(language_stats)
    
    # Load latest solutions section
    latest_solutions_section = load_latest_solutions_section()
    
    # Update README
    update_readme(language_section, latest_solutions_section)
    
    print("README updated successfully!")
