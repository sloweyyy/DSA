use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> Vec<Vec<i32>> {
        fn visit(root: Option<Rc<RefCell<TreeNode>>>, remaining: i32, path: &mut Vec<i32>, result: &mut Vec<Vec<i32>>) {
            if let Some(node) = root {
                let node = node.borrow();
                path.push(node.val);
                let remaining = remaining - node.val;
                if node.left.is_none() && node.right.is_none() {
                    if remaining == 0 {
                        result.push(path.clone());
                    }
                }
                else {
                    visit(node.left.clone(), remaining, path, result);
                    visit(node.right.clone(), remaining, path, result);
                }
                path.pop();
            }
        }
        let mut result = Vec::new();
        visit(root, target_sum, &mut Vec::new(), &mut result);
        result
    }
}
