class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function minimizeSum($nums) {
        sort($nums, SORT_NUMERIC);
        $n = count($nums);

        return min(
            $nums[$n - 1] - $nums[2],
            $nums[$n - 2] - $nums[1],
            $nums[$n - 3] - $nums[0]
        );
    }
}
