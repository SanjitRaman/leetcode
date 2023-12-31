#include "../tools/leetcode_binary_tree_helper.h"


class Solution {
public:
	std::vector < std::vector<int>> levelOrder(TreeNode* root) {
		// Given the root of a binary tree, return the level order traversal of its nodes' values.
		// i.e. from left to right, level by level.

		// base case: 
		if (root == nullptr) return { };

		// solve using a queue:
		// keep track of the level
		std::queue<std::pair<int, TreeNode*>> q;

		// add the root
		q.push(std::make_pair(0, root));

		// store the result.
		std::vector<std::vector<int>> level_order;

		std::vector<int> row;
		int prev_height = 0;

		while (!q.empty()) {

			std::pair<int, TreeNode*> node = q.front();
			q.pop();

			// moved on to a new height
			if (node.first != prev_height) {
				// submit the row
				level_order.push_back(row);
				// reset the row
				row.clear();
				// update the prev_height
				prev_height = node.first;
			}

			row.push_back(node.second->val);
			// if not null, push children to queue, with height of n+1
			// where n is the height of the current node = node.first
			if (node.second->left != nullptr) q.push(std::make_pair(node.first + 1, node.second->left));
			if (node.second->right != nullptr) q.push(std::make_pair(node.first + 1, node.second->right));

		}
		// last row will not be pushed.
		if (!row.empty()) level_order.push_back(row);

		return level_order;
	}
};

int main() {

	BinaryTreeHelper bth;
	Solution s;

	std::queue<std::string> q = bth.queue_binary_tree();
	TreeNode* bt = bth.construct_binary_tree(q);

	std::vector<std::vector<int>> v = s.levelOrder(bt);

	return 0;
}