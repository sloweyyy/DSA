bool canMeasureWater(int x, int y, int target) {
    if (target > x + y) return false;
    while (y != 0) {
        int remainder = x % y;
        x = y;
        y = remainder;
    }
    return target % x == 0;
}
