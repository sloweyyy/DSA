// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
use std::cmp::max;
impl Solution {
    pub fn max_product(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        const MOD: i64 = 1_000_000_007;

        // First pass: calculate total sum
        let total_sum = Self::calculate_sum(&root);

        // Second pass: calculate subtree sums and find max product
        let mut max_product: i64 = 0;
        Self::dfs(&root, total_sum, &mut max_product);

        (max_product % MOD) as i32
    }

    fn calculate_sum(root: &Option<Rc<RefCell<TreeNode>>>) -> i64 {
        if let Some(node) = root {
            let node_ref = node.borrow();
            node_ref.val as i64 + Self::calculate_sum(&node_ref.left) + Self::calculate_sum(&node_ref.right)
        } else {
            0
        }
    }

    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, total_sum: i64, max_product: &mut i64) -> i64 {
        if let Some(node) = root {
            let node_ref = node.borrow();
            let left_sum = Self::dfs(&node_ref.left, total_sum, max_product);
            let right_sum = Self::dfs(&node_ref.right, total_sum, max_product);
            let subtree_sum = node_ref.val as i64 + left_sum + right_sum;

            // The product of this subtree and the rest of the tree
            let product = subtree_sum * (total_sum - subtree_sum);
            *max_product = max(*max_product, product);

            subtree_sum
        } else {
            0
        }
    }
}
