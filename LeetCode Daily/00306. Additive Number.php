class Solution {
    private function addNumbers($a, $b) {
        $i = strlen($a) - 1;
        $j = strlen($b) - 1;
        $carry = 0;
        $digits = "";
        while ($i >= 0 || $j >= 0 || $carry > 0) {
            $sum = $carry;
            if ($i >= 0) $sum += ord($a[$i--]) - 48;
            if ($j >= 0) $sum += ord($b[$j--]) - 48;
            $digits .= chr(48 + $sum % 10);
            $carry = intdiv($sum, 10);
        }
        return strrev($digits);
    }
    function isAdditiveNumber($num) {
        $length = strlen($num);
        for ($first = 1; $first < $length - 1; $first++) {
            if ($first > 1 && $num[0] === "0") break;
            for ($second = $first + 1; $second < $length; $second++) {
                if ($second > $first + 1 && $num[$first] === "0") break;
                if ($length - $second < max($first, $second - $first)) break;
                $a = substr($num, 0, $first);
                $b = substr($num, $first, $second - $first);
                $position = $second;
                while ($position < $length) {
                    $sum = $this->addNumbers($a, $b);
                    $width = strlen($sum);
                    if (substr($num, $position, $width) !== $sum) break;
                    $position += $width;
                    $a = $b;
                    $b = $sum;
                }
                if ($position === $length) return true;
            }
        }
        return false;
    }
}
