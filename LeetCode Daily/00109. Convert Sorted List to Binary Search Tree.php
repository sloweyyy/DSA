class Solution {
    function sortedListToBST($head) {
        $size = 0;
        for ($node = $head; $node !== null; $node = $node->next) {
            $size++;
        }
        $current = $head;
        return $this->build($size, $current);
    }
    private function build($size, &$current) {
        if ($size === 0) return null;
        $leftSize = intdiv($size, 2);
        $left = $this->build($leftSize, $current);
        $root = new TreeNode($current->val);
        $current = $current->next;
        $root->left = $left;
        $root->right = $this->build($size - $leftSize - 1, $current);
        return $root;
    }
}
