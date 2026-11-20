class Solution {
    List<List<String>> partition(String s) {
        final n = s.length;
        final palindrome = List.generate(n, (_) => List<bool>.filled(n, false));
        for (int start = n - 1; start >= 0; start--) {
            for (int end = start; end < n; end++) {
                palindrome[start][end] = s[start] == s[end] && (end - start < 2 || palindrome[start + 1][end - 1]);
            }
        }
        final result = <List<String>>[];
        final path = <String>[];
        void visit(int start) {
            if (start == n) {
                result.add(List<String>.from(path));
                return;
            }
            for (int end = start; end < n; end++) {
                if (palindrome[start][end]) {
                    path.add(s.substring(start, end + 1));
                    visit(end + 1);
                    path.removeLast();
                }
            }
        }
        visit(0);
        return result;
    }
}
