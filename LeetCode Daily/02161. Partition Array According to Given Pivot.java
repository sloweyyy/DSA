
class Solution {

    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int[] result = new int[n];

        // Count elements less than, equal to, and greater than pivot
        int lessThanCount = 0;
        int equalCount = 0;

        for (int num : nums) {
            if (num < pivot) {
                lessThanCount++;
            } else if (num == pivot) {
                equalCount++;
            }
        }

        // Initialize positions for each group
        int lessThanIndex = 0;
        int equalIndex = lessThanCount;
        int greaterIndex = lessThanCount + equalCount;

        // Fill the result array
        for (int num : nums) {
            if (num < pivot) {
                result[lessThanIndex++] = num;
            } else if (num == pivot) {
                result[equalIndex++] = num;
            } else {
                result[greaterIndex++] = num;
            }
        }

        return result;
    }
}
