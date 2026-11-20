class Solution {
    function deserialize($s) {
        if ($s[0] !== "[") return new NestedInteger((int)$s);
        $stack = [];
        $number = 0;
        $sign = 1;
        $hasNumber = false;
        $root = null;
        for ($i = 0; $i < strlen($s); $i++) {
            $character = $s[$i];
            $digit = ord($character) - 48;
            if ($character === "[") {
                $stack[] = new NestedInteger();
            }
            elseif ($character === "-") {
                $sign = -1;
            }
            elseif ($digit >= 0 && $digit <= 9) {
                $number = $number * 10 + $digit;
                $hasNumber = true;
            }
            else {
                if ($hasNumber) {
                    $stack[count($stack) - 1]->add(new NestedInteger($sign * $number));
                    $number = 0;
                    $sign = 1;
                    $hasNumber = false;
                }
                if ($character === "]") {
                    $completed = array_pop($stack);
                    if (count($stack) > 0) $stack[count($stack) - 1]->add($completed);
                    else $root = $completed;
                }
            }
        }
        return $root;
    }
}
