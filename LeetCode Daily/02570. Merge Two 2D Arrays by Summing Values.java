
class Solution {

    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        Map<Integer, Integer> mergedMap = new TreeMap<>(); // TreeMap maintains sorted order

        // Add all values from nums1
        for (int[] pair : nums1) {
            mergedMap.put(pair[0], pair[1]);
        }

        // Add or update with values from nums2
        for (int[] pair : nums2) {
            mergedMap.put(pair[0], mergedMap.getOrDefault(pair[0], 0) + pair[1]);
        }

        // Convert map to result array
        int[][] result = new int[mergedMap.size()][2];
        int index = 0;

        for (Map.Entry<Integer, Integer> entry : mergedMap.entrySet()) {
            result[index][0] = entry.getKey();
            result[index][1] = entry.getValue();
            index++;
        }

        return result;
    }
}
