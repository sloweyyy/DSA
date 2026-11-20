class Solution extends VersionControl {
    function firstBadVersion($n) {
        $left = 1;
        $right = $n;
        while ($left < $right) {
            $middle = $left + intdiv($right - $left, 2);
            if ($this->isBadVersion($middle)) $right = $middle;
            else $left = $middle + 1;
        }
        return $left;
    }
}
