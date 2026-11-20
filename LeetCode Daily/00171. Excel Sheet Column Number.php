class Solution {
    function titleToNumber($columnTitle) {
        $number = 0;
        for ($i = 0; $i < strlen($columnTitle); $i++) {
            $number = $number * 26 + ord($columnTitle[$i]) - ord("A") + 1;
        }
        return $number;
    }
}
