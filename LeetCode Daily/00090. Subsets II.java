class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<>());
        int previousStart = 0;
        for (int i = 0; i < nums.length; i++) {
            int size = result.size();
            int start = i > 0 && nums[i] == nums[i - 1] ? previousStart : 0;
            for (int j = start; j < size; j++) {
                List<Integer> subset = new ArrayList<>(result.get(j));
                subset.add(nums[i]);
                result.add(subset);
            }
            previousStart = size;
        }
        return result;
    }
}
