class Solution {
    function calculate($s) {
        $total = 0;
        $term = 0;
        $number = 0;
        $operator = "+";
        $length = strlen($s);
        for ($i = 0; $i <= $length; $i++) {
            $character = $i < $length ? $s[$i] : "+";
            $digit = ord($character) - 48;
            if ($digit >= 0 && $digit <= 9) {
                $number = $number * 10 + $digit;
            }
            elseif ($character !== " ") {
                if ($operator === "+") {
                    $total += $term;
                    $term = $number;
                }
                elseif ($operator === "-") {
                    $total += $term;
                    $term = -$number;
                }
                elseif ($operator === "*") {
                    $term *= $number;
                }
                else {
                    $term = intdiv($term, $number);
                }
                $number = 0;
                $operator = $character;
            }
        }
        return $total + $term;
    }
}
