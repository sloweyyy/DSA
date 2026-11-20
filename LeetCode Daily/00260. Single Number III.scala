object Solution {
    def singleNumber(nums: Array[Int]): Array[Int] = {
        var combined = 0;
        for (value <- nums) {
            combined ^= value;
        };
        val mask = combined & -combined;
        var first = 0;
        for (value <- nums) {
            if ((value & mask) == 0) first ^= value;
        };
        Array(first, combined ^ first)
    }
}
