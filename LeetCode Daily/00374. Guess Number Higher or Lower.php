class Solution extends GuessGame {
    function guessNumber($n) {
        $left = 1;
        $right = $n;
        while ($left <= $right) {
            $middle = $left + intdiv($right - $left, 2);
            $comparison = $this->guess($middle);
            if ($comparison === 0) return $middle;
            if ($comparison < 0) $right = $middle - 1;
            else $left = $middle + 1;
        }
        return -1;
    }
}
