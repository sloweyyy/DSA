class Solution {
    function originalDigits($s) {
        $letters = count_chars($s, 0);
        $digits = array_fill(0, 10, 0);
        $digits[0] = $letters[ord("z")];
        $digits[2] = $letters[ord("w")];
        $digits[4] = $letters[ord("u")];
        $digits[6] = $letters[ord("x")];
        $digits[8] = $letters[ord("g")];
        $digits[3] = $letters[ord("h")] - $digits[8];
        $digits[5] = $letters[ord("f")] - $digits[4];
        $digits[7] = $letters[ord("s")] - $digits[6];
        $digits[1] = $letters[ord("o")] - $digits[0] - $digits[2] - $digits[4];
        $digits[9] = $letters[ord("i")] - $digits[5] - $digits[6] - $digits[8];
        $result = "";
        for ($digit = 0; $digit <= 9; $digit++) $result .= str_repeat((string)$digit, $digits[$digit]);
        return $result;
    }
}
