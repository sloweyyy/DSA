class Solution {
    function calculate($s) {
        $result = 0;
        $number = 0;
        $sign = 1;
        $stack = [];
        $length = strlen($s);
        for ($i = 0; $i < $length; $i++) {
            $character = $s[$i];
            $digit = ord($character) - 48;
            if ($digit >= 0 && $digit <= 9) {
                $number = $number * 10 + $digit;
            }
            elseif ($character === "+" || $character === "-") {
                $result += $sign * $number;
                $number = 0;
                $sign = $character === "+" ? 1 : -1;
            }
            elseif ($character === "(") {
                $stack[] = $result;
                $stack[] = $sign;
                $result = 0;
                $number = 0;
                $sign = 1;
            }
            elseif ($character === ")") {
                $result += $sign * $number;
                $number = 0;
                $result *= array_pop($stack);
                $result += array_pop($stack);
            }
        }
        return $result + $sign * $number;
    }
}
