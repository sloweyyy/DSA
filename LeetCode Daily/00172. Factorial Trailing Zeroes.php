class Solution {
    function trailingZeroes($n) {
        $zeroes = 0;
        while ($n > 0) {
            $n = intdiv($n, 5);
            $zeroes += $n;
        }
        return $zeroes;
    }
}
