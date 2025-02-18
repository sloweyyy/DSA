
class Solution {

    public String smallestNumber(String pattern) {
        StringBuilder result = new StringBuilder();
        Stack<Integer> stack = new Stack<>();

        // Initialize with 1 to n+1 numbers
        for (int i = 0; i <= pattern.length(); i++) {
            stack.push(i + 1);

            // When we see 'I' or reach the end, pop everything from stack
            if (i == pattern.length() || pattern.charAt(i) == 'I') {
                while (!stack.isEmpty()) {
                    result.append(stack.pop());
                }
            }
        }

        return result.toString();
    }
}
