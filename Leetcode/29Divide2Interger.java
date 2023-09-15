class Solution {
    public int divide(int dividend, int divisor) {
        int sign = 1;
        if (dividend < 0) {
            sign *= -1;
        }
        if (divisor < 0) {
            sign *= -1;
        }
        long dividend1 = Math.abs((long) dividend);
        long divisor1 = Math.abs((long) divisor);
        long ans = 0;
        while (dividend1 >= divisor1) {
            long temp = divisor1;
            long count = 1;
            while (dividend1 >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }
            dividend1 -= temp;
            ans += count;
        }
        ans *= sign;
        if (ans > Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        }
        if (ans < Integer.MIN_VALUE) {
            return Integer.MIN_VALUE;
        }
        return (int) ans;

    }

}

public static void main(String[] args) {
    Solution sol = new Solution();
    int dividend = 10;
    int divisor = 3;
    System.out.println(sol.divide(dividend, divisor));
}