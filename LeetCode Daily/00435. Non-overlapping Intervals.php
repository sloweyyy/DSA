class Solution {
    function eraseOverlapIntervals($intervals) {
        usort($intervals, fn($a, $b) => $a[1] <=> $b[1]);
        $end = PHP_INT_MIN;
        $removed = 0;
        foreach ($intervals as $interval) {
            if ($interval[0] < $end) $removed++;
            else $end = $interval[1];
        }
        return $removed;
    }
}
