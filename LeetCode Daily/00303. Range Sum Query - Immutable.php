class NumArray {
    private $prefix = [0];
    function __construct($nums) {
        $sum = 0;
        foreach ($nums as $number) {
            $sum += $number;
            $this->prefix[] = $sum;
        }
    }
    function sumRange($left, $right) {
        return $this->prefix[$right + 1] - $this->prefix[$left];
    }
}
