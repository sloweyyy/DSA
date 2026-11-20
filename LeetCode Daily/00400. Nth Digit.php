class Solution {
    function findNthDigit($n) {
        $digits = 1;
        $count = 9;
        $start = 1;
        while ($n > $digits * $count) {
            $n -= $digits * $count;
            $digits++;
            $count *= 10;
            $start *= 10;
        }
        $number = $start + intdiv($n - 1, $digits);
        $text = (string)$number;
        return ord($text[($n - 1) % $digits]) - 48;
    }
}
