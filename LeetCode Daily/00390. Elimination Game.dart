class Solution {
    int lastRemaining(int n) {
        int first = 1;
        int step = 1;
        int remaining = n;
        bool leftToRight = true;
        while (remaining > 1) {
            if (leftToRight || remaining.isOdd) first += step;
            remaining ~/= 2;
            step *= 2;
            leftToRight = !leftToRight;
        }
        return first;
    }
}
