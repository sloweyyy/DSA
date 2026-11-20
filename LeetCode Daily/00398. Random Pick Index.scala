class Solution(_nums: Array[Int]) {
    private val positions = scala.collection.mutable.HashMap.empty[Int, scala.collection.mutable.ArrayBuffer[Int]];
    private val random = new scala.util.Random();
    for (index <- _nums.indices) {
        positions.getOrElseUpdate(_nums(index), scala.collection.mutable.ArrayBuffer.empty[Int]) += index;
    };
    def pick(target: Int): Int = {
        val indices = positions(target);
        indices(random.nextInt(indices.length))
    }
}
