class Solution {
    public int repeatedNTimes(int[] nums) {
      Map<Integer, Integer> map = new HashMap<>();
      for (int num : nums) {
        map.put(num, map.getOrDefault(num, 0) + 1);
      }
      for (int num : map.keySet()) {
        if (map.get(num) == nums.length / 2) {
          return num;
        }
      }
      return -1;
    }
}