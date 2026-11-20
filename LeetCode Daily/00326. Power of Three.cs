public class Solution {
    public bool IsPowerOfThree(int n) {
        const int largestPowerOfThree = 1162261467;
        return n > 0 && largestPowerOfThree % n == 0;
    }
}
