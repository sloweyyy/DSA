object Solution {
    def combinationSum3(k: Int, n: Int): List[List[Int]] = {
        def choose(start: Int, left: Int, target: Int): List[List[Int]] = {
            if (left == 0) {
                if (target == 0) List(Nil) else Nil
            }
            else {
                (start to 9).toList.filter(_ <= target).flatMap(value => choose(value + 1, left - 1, target - value).map(value :: _))
            }
        };
        choose(1, k, n)
    }
}
