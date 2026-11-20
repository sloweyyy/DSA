object Solution {
    def minPatches(nums: Array[Int], n: Int): Int = {
        var missing = 1L;
        var index = 0;
        var patches = 0;
        while (missing <= n.toLong) {
            if (index < nums.length && nums(index).toLong <= missing) {
                missing += nums(index);
                index += 1;
            }
            else {
                missing *= 2;
                patches += 1;
            }
        };
        patches
    }
}
