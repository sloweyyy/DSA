#!/usr/bin/env python3
"""
Git Hooks Setup Script

This script sets up Git hooks to automatically update your README when you commit new LeetCode solutions.
"""

import os
import stat
import subprocess


def create_post_commit_hook():
    """Create a post-commit hook that updates README after commits."""
    
    hook_content = '''#!/bin/bash
# Post-commit hook to update README with latest LeetCode solutions

echo "🔍 Checking for new LeetCode solutions..."

# Run the update script
python3 update_latest_solutions.py

# Check if there were any changes to the solutions
if [ -f "latest_solutions_section.txt" ]; then
    echo "📝 Updating README with latest solutions..."
    python3 update_readme_with_solutions.py
    
    # Check if README was modified
    if git diff --quiet README.md; then
        echo "✅ No changes to README needed"
    else
        echo "📋 README updated with latest solutions"
        echo "💡 Consider committing the updated README:"
        echo "    git add README.md"
        echo "    git commit -m 'Update README with latest solutions'"
    fi
else
    echo "ℹ️  No new LeetCode solutions found in this commit"
fi
'''
    
    # Create .git/hooks directory if it doesn't exist
    hooks_dir = '.git/hooks'
    if not os.path.exists(hooks_dir):
        os.makedirs(hooks_dir)
    
    # Write the hook file
    hook_path = os.path.join(hooks_dir, 'post-commit')
    with open(hook_path, 'w') as f:
        f.write(hook_content)
    
    # Make the hook executable
    st = os.stat(hook_path)
    os.chmod(hook_path, st.st_mode | stat.S_IEXEC)
    
    print(f"✅ Created post-commit hook at {hook_path}")


def create_pre_push_hook():
    """Create a pre-push hook that ensures README is up to date before pushing."""
    
    hook_content = '''#!/bin/bash
# Pre-push hook to ensure README is updated before pushing

echo "🔍 Checking if README needs updating before push..."

# Run the update script to check for any new solutions
python3 update_latest_solutions.py

# Update README
python3 update_readme_with_solutions.py

# Check if README was modified
if ! git diff --quiet README.md; then
    echo "⚠️  README has been updated with latest solutions"
    echo "📋 The following changes were made to README.md:"
    git diff --stat README.md
    echo ""
    echo "❌ Push cancelled. Please review and commit the README changes:"
    echo "    git add README.md"
    echo "    git commit -m 'Update README with latest solutions'"
    echo "    git push"
    exit 1
fi

echo "✅ README is up to date"
'''
    
    # Create .git/hooks directory if it doesn't exist
    hooks_dir = '.git/hooks'
    if not os.path.exists(hooks_dir):
        os.makedirs(hooks_dir)
    
    # Write the hook file
    hook_path = os.path.join(hooks_dir, 'pre-push')
    with open(hook_path, 'w') as f:
        f.write(hook_content)
    
    # Make the hook executable
    st = os.stat(hook_path)
    os.chmod(hook_path, st.st_mode | stat.S_IEXEC)
    
    print(f"✅ Created pre-push hook at {hook_path}")


def setup_auto_commit_hook():
    """Create a post-commit hook that automatically commits README updates."""
    
    hook_content = '''#!/bin/bash
# Post-commit hook that automatically updates and commits README

echo "🔍 Checking for new LeetCode solutions..."

# Run the update script
python3 update_latest_solutions.py

# Check if there were any changes to the solutions
if [ -f "latest_solutions_section.txt" ]; then
    echo "📝 Updating README with latest solutions..."
    python3 update_readme_with_solutions.py
    
    # Check if README was modified
    if ! git diff --quiet README.md; then
        echo "📋 README updated with latest solutions"
        echo "🚀 Auto-committing README update..."
        
        git add README.md latest_solutions.json latest_solutions_section.txt
        git commit -m "📝 Update README with latest LeetCode solutions
        
Auto-generated commit from post-commit hook"
        
        echo "✅ README automatically updated and committed"
    else
        echo "✅ No changes to README needed"
    fi
else
    echo "ℹ️  No new LeetCode solutions found in this commit"
fi
'''
    
    # Create .git/hooks directory if it doesn't exist
    hooks_dir = '.git/hooks'
    if not os.path.exists(hooks_dir):
        os.makedirs(hooks_dir)
    
    # Write the hook file
    hook_path = os.path.join(hooks_dir, 'post-commit')
    with open(hook_path, 'w') as f:
        f.write(hook_content)
    
    # Make the hook executable
    st = os.stat(hook_path)
    os.chmod(hook_path, st.st_mode | stat.S_IEXEC)
    
    print(f"✅ Created auto-commit post-commit hook at {hook_path}")


def remove_hooks():
    """Remove existing Git hooks."""
    hooks_to_remove = ['post-commit', 'pre-push']
    
    for hook_name in hooks_to_remove:
        hook_path = os.path.join('.git/hooks', hook_name)
        if os.path.exists(hook_path):
            os.remove(hook_path)
            print(f"🗑️  Removed {hook_name} hook")


def main():
    print("🔧 Git Hooks Setup for LeetCode README Automation")
    print("=" * 50)
    
    if not os.path.exists('.git'):
        print("❌ Error: This is not a Git repository")
        return
    
    print("\nChoose an option:")
    print("1. Manual notification (post-commit hook notifies you to update README)")
    print("2. Pre-push validation (ensures README is updated before pushing)")
    print("3. Auto-commit (automatically commits README updates)")
    print("4. Remove all hooks")
    print("5. Exit")
    
    choice = input("\nEnter your choice (1-5): ").strip()
    
    if choice == '1':
        remove_hooks()
        create_post_commit_hook()
        print("\n✅ Manual notification hook installed!")
        print("📋 After each commit, you'll be notified if README needs updating")
        
    elif choice == '2':
        remove_hooks()
        create_pre_push_hook()
        print("\n✅ Pre-push validation hook installed!")
        print("🚫 Pushes will be blocked if README is not up to date")
        
    elif choice == '3':
        remove_hooks()
        setup_auto_commit_hook()
        print("\n✅ Auto-commit hook installed!")
        print("🚀 README will be automatically updated and committed after each commit")
        print("⚠️  Warning: This creates additional commits automatically")
        
    elif choice == '4':
        remove_hooks()
        print("\n✅ All hooks removed!")
        
    elif choice == '5':
        print("👋 Goodbye!")
        
    else:
        print("❌ Invalid choice. Please run the script again.")


if __name__ == "__main__":
    main()
