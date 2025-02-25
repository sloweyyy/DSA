
class Solution {

    public int numOfSubarrays(int[] arr) {
        int n = arr.length;
        int mod = 1000000007;
        int odd = 0, even = 1, sum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum % 2 == 0) {
                res = (res + odd) % mod;
                even++;
            } else {
                res = (res + even) % mod;
                odd++;
            }
        }
        return res;
    }
}
