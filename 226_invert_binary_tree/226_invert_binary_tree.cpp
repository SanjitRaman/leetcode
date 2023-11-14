#include "../tools/leetcode_binary_tree_helper.h"

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		// recursive implementation:
		// switch left and right node.
		// switch children of left node (invertTree(root->left))
		// switch children of right node (invertTree(root->right))

		// base case:
		// root is null, nothing to invert:
		if (root == nullptr) return root;
		// both children null, nothing to invert:
		if (root->left == nullptr && root->right == nullptr) return root;

		TreeNode* tmp = invertTree(root->left);
		root->left = invertTree(root->right);
		root->right = tmp;

		return root;
	}
};

int main() {
	BinaryTreeHelper bth;
	std::queue<std::string> q = bth.queue_binary_tree();
	TreeNode* bt = bth.construct_binary_tree(q);


	Solution s;
	bt = s.invertTree(bt);
}