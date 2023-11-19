#include "../tools/leetcode_binary_tree_helper.h"

class Solution {
private:
	void inorder(TreeNode* root, std::vector<int>& result) {
		if (root == nullptr) return;

		// Traverse the left subtree
		inorder(root->left, result);
		result.push_back(root->val);
		inorder(root->right, result);
	}

public:

	std::vector<int> inorderTraversal(TreeNode * root) {
		std::vector<int> result;
		inorder(root, result);
		return result;
	}
};


int main() {
	BinaryTreeHelper bth;
	Solution s;
	std::vector<int> inorder_traversal;

	std::queue<std::string> q1 = bth.queue_binary_tree();
	TreeNode* bt1 = bth.construct_binary_tree(q1);
	inorder_traversal = s.inorderTraversal(bt1);
	for (int i = 0; i < inorder_traversal.size(); i++) std::cout << inorder_traversal[i] << " ";
	std::cout << std:: endl;

	std::queue<std::string> q2 = bth.queue_binary_tree();
	TreeNode* bt2 = bth.construct_binary_tree(q2);
	inorder_traversal = s.inorderTraversal(bt2);
	for (int i = 0; i < inorder_traversal.size(); i++) std::cout << inorder_traversal[i] << " ";
	std::cout << std::endl;

	std::queue<std::string> q3 = bth.queue_binary_tree();
	TreeNode* bt3 = bth.construct_binary_tree(q3);
	inorder_traversal = s.inorderTraversal(bt3);
	for (int i = 0; i < inorder_traversal.size(); i++) std::cout << inorder_traversal[i] << " ";
	std::cout << std::endl;


	return 0;
}