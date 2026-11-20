use std::rc::Rc;
use std::cell::RefCell;
struct Codec {
}
impl Codec {
    fn new() -> Self {
        Self {
        }
    }
    fn serialize(&self, root: Option<Rc<RefCell<TreeNode>>>) -> String {
        let mut values = Vec::new();
        let mut stack = Vec::new();
        if let Some(node) = root {
            stack.push(node);
        }
        while let Some(node) = stack.pop() {
            let node = node.borrow();
            values.push(node.val.to_string());
            if let Some(right) = node.right.clone() {
                stack.push(right);
            }
            if let Some(left) = node.left.clone() {
                stack.push(left);
            }
        }
        values.join(",")
    }
    fn deserialize(&self, data: String) -> Option<Rc<RefCell<TreeNode>>> {
        fn build(values: &[i32], index: &mut usize, low: i64, high: i64) -> Option<Rc<RefCell<TreeNode>>> {
            if *index == values.len() {
                return None;
            }
            let value = values[*index] as i64;
            if value <= low || value >= high {
                return None;
            }
            *index += 1;
            let mut node = TreeNode::new(value as i32);
            node.left = build(values, index, low, value);
            node.right = build(values, index, value, high);
            Some(Rc::new(RefCell::new(node)))
        }
        let values: Vec<i32> = data.split(',').filter(|s| !s.is_empty()).map(|s| s.parse().unwrap()).collect();
        build(&values, &mut 0, i64::MIN, i64::MAX)
    }
}
