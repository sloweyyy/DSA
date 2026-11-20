class Solution {
    function calculateMinimumHP($dungeon) {
        $rows = count($dungeon);
        $columns = count($dungeon[0]);
        $health = array_fill(0, $columns + 1, PHP_INT_MAX);
        $health[$columns - 1] = 1;
        for ($row = $rows - 1; $row >= 0; $row--) {
            for ($column = $columns - 1; $column >= 0; $column--) {
                $health[$column] = max(1, min($health[$column], $health[$column + 1]) - $dungeon[$row][$column]);
            }
        }
        return $health[0];
    }
}
