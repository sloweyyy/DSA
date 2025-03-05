
class Solution {

    public boolean checkPowersOfThree(int n) {
        // Convert n to base 3
        String base3 = Integer.toString(n, 3);

        // Check if base 3 representation contains 2
        return !base3.contains("2");
    }
}
