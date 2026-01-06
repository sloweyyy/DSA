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
impl Solution {
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        use std::collections::VecDeque;
        let mut queue = VecDeque::new();
        queue.push_back(root);
        let mut max_sum = i32::MIN;
        let mut result_level = 1;
        let mut current_level = 1;

        while !queue.is_empty() {
            let level_size = queue.len();
            let mut current_sum = 0;

            for _ in 0..level_size {
                if let Some(Some(node)) = queue.pop_front() {
                    let node_ref = node.borrow();
                    current_sum += node_ref.val;

                    if node_ref.left.is_some() {
                        queue.push_back(node_ref.left.clone());
                    }
                    if node_ref.right.is_some() {
                        queue.push_back(node_ref.right.clone());
                    }
                }
            }

            if current_sum > max_sum {
                max_sum = current_sum;
                result_level = current_level;
            }
            current_level += 1;
        }

        result_level       
    }
}