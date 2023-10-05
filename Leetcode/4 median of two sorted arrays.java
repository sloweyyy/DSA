class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] nums = new int[nums1.length + nums2.length];

        int i = 0, j = 0, k = 0;
        while (i < nums1.length && j < nums2.length)
            nums[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];

        while (i < nums1.length)
            nums[k++] = nums1[i++];

        while (j < nums2.length)
            nums[k++] = nums2[j++];

        if (nums.length % 2 == 0)
            return (nums[nums.length / 2 - 1] + nums[nums.length / 2]) / 2.0;
        else
            return nums[nums.length / 2];
    }
}