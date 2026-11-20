class Solution {
    function recoverTree($root) {
        $first = null;
        $second = null;
        $previous = null;
        $current = $root;
        while ($current !== null) {
            if ($current->left !== null) {
                $predecessor = $current->left;
                while ($predecessor->right !== null && $predecessor->right !== $current) {
                    $predecessor = $predecessor->right;
                }
                if ($predecessor->right === null) {
                    $predecessor->right = $current;
                    $current = $current->left;
                    continue;
                }
                $predecessor->right = null;
            }
            if ($previous !== null && $previous->val > $current->val) {
                if ($first === null) $first = $previous;
                $second = $current;
            }
            $previous = $current;
            $current = $current->right;
        }
        $value = $first->val;
        $first->val = $second->val;
        $second->val = $value;
    }
}
