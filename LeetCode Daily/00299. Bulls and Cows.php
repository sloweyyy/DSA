class Solution {
    function getHint($secret, $guess) {
        $bulls = 0;
        $secretCounts = array_fill(0, 10, 0);
        $guessCounts = array_fill(0, 10, 0);
        for ($i = 0; $i < strlen($secret); $i++) {
            if ($secret[$i] === $guess[$i]) $bulls++;
            else {
                $secretCounts[ord($secret[$i]) - 48]++;
                $guessCounts[ord($guess[$i]) - 48]++;
            }
        }
        $cows = 0;
        for ($digit = 0; $digit < 10; $digit++) $cows += min($secretCounts[$digit], $guessCounts[$digit]);
        return $bulls . "A" . $cows . "B";
    }
}
