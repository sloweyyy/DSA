object Solution {
    def containsDuplicate(nums: Array[Int]): Boolean = {
        val seen = scala.collection.mutable.HashSet.empty[Int];
        nums.exists(value => !seen.add(value))
    }
}
