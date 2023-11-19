#include "../tools/leetcode_binary_tree_helper.h"

class Solution {
private:
	bool isMirror(TreeNode* a, TreeNode* b) {
		// base case
		if (a == nullptr && b == nullptr) return true;
		if (a == nullptr || b == nullptr) return false;

		// inductive step
		// check the value is the same.
		if (a->val != b->val) return false;
		return isMirror(a->left, b->right) && isMirror(a->right, b->left);

	}

public:
	bool isSymmetric(TreeNode* root) {
		// base case
		if (root == nullptr) return true;
		// inductive step
		return isMirror(root->left, root->right);
	}
};

int main() {

	BinaryTreeHelper bth;
	Solution s;

	// Solve a first test
	std::queue <std::string> q1 = bth.queue_binary_tree();
	TreeNode* bt1 = bth.construct_binary_tree(q1);
	std::cout << (s.isSymmetric(bt1) ? "Symmetric" : "Not Symmetric") << std::endl;

	// Solve a second test
	std::queue<std::string> q2 = bth.queue_binary_tree();
	TreeNode* bt2 = bth.construct_binary_tree(q2);
	std::cout << (s.isSymmetric(bt2) ? "Symmetric" : "Not Symmetric") << std::endl;



	return 0;
}