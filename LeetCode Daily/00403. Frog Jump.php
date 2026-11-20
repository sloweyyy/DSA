class Solution {
    function canCross($stones) {
        if ($stones[1] !== 1) return false;
        $exists = array_fill_keys($stones, true);
        $last = $stones[count($stones) - 1];
        $reachable = [0 => [0 => true]];
        foreach ($stones as $position) {
            foreach (($reachable[$position] ?? []) as $jump => $_) {
                for ($step = max(1, $jump - 1); $step <= $jump + 1; $step++) {
                    $landing = $position + $step;
                    if ($landing === $last) return true;
                    if (isset($exists[$landing])) $reachable[$landing][$step] = true;
                }
            }
        }
        return false;
    }
}
