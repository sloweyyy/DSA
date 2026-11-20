class Solution {
    function findRightInterval($intervals) {
        $starts = [];
        foreach ($intervals as $i => $interval) $starts[] = [$interval[0], $i];
        usort($starts, fn($a, $b) => $a[0] <=> $b[0]);
        $n = count($starts);
        $answer = [];
        foreach ($intervals as $interval) {
            $left = 0;
            $right = $n;
            while ($left < $right) {
                $mid = intdiv($left + $right, 2);
                if ($starts[$mid][0] < $interval[1]) $left = $mid + 1;
                else $right = $mid;
            }
            $answer[] = $left == $n ? -1 : $starts[$left][1];
        }
        return $answer;
    }
}
