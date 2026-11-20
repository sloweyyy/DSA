object Solution {
    def isSelfCrossing(distance: Array[Int]): Boolean = {
        var i = 3;
        while (i < distance.length) {
            if (distance(i) >= distance(i - 2) && distance(i - 1) <= distance(i - 3)) return true;
            if (i >= 4 && distance(i - 1) == distance(i - 3) && distance(i) + distance(i - 4) >= distance(i - 2)) return true;
            if (i >= 5 && distance(i - 2) >= distance(i - 4) && distance(i) + distance(i - 4) >= distance(i - 2) && distance(i - 1) <= distance(i - 3) && distance(i - 1) + distance(i - 5) >= distance(i - 3)) return true;
            i += 1;
        };
        false
    }
}
