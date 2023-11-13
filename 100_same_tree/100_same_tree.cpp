#include "../tools/leetcode_binary_tree_helper.h"

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		// base case: 
		if (p == nullptr && q == nullptr) return true;
		// if only one of the nodes is null, they are not identical:
		if ((p == nullptr) || (q == nullptr)) return false;
		

		// inductive step:
		// check if values are equal and recursively check left and right subtrees
		if (p->val == q->val)
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

		return false;
	}
};

int main() {
	BinaryTreeHelper bth;
	std::queue<int> q1 = bth.queue_binary_tree();
	std::queue<int> q2 = bth.queue_binary_tree();

	TreeNode* p = bth.construct_binary_tree(q1);
	TreeNode* q = bth.construct_binary_tree(q2);

	Solution s;
	bool result = s.isSameTree(p, q);

	std::cout << result << std::endl;
	
}