// 2236. Root Equals Sum of Children
// Source: https://leetcode.com/problems/root-equals-sum-of-children/
// Author: Sanjit Raman

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}
use std::cell::RefCell;
use std::rc::Rc;
struct Solution;
impl Solution {
    pub fn check_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        // reading stanislav-iablokov's solution
        // source: https://leetcode.com/problems/root-equals-sum-of-children/solutions/2603021/rust-0-ms-simple-solution-with-detailed-comments

        // "Unfortunately, in Rust the use of smart pointers is challenging due to security issues."
        // Furthermore, "an `Option` requires unwrapping."

        // [1] unpack smart pointer and borrow TreeNode
        let root_node = root.as_ref().unwrap().borrow();

        // [2] unpack left and right smart pointers and borrow their TreeNodes
        let left_node = root_node.left.as_ref().unwrap().borrow();
        let right_node = root_node.right.as_ref().unwrap().borrow();

        return root_node.val == left_node.val + right_node.val;
    }
}

// tests
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        let mut root = TreeNode::new(3);
        let left = TreeNode::new(1);
        let right = TreeNode::new(2);
        root.left = Some(Rc::new(RefCell::new(left)));
        root.right = Some(Rc::new(RefCell::new(right)));

        assert_eq!(
            Solution::check_tree(Some(Rc::new(RefCell::new(root)))),
            true
        );
    }
}

fn main() {}
