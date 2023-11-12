#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <regex>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BinaryTreeHelper {
private:
    TreeNode* recurse_level_order(TreeNode* root, std::queue<int>& q) {
        if (!q.empty()) {
            if (q.front() != INT_MIN) root->left = new TreeNode(q.front());
            q.pop();
        }
        if (!q.empty()) {
            if (q.front() != INT_MIN) root->right = new TreeNode(q.front());
            q.pop();
        }

        if (root->left != nullptr) {
            root->left = recurse_level_order(root->left, q);
        }
        if (root->right != nullptr) {
            root->right = recurse_level_order(root->right, q);
        }

        return root;
    }
public:
    std::queue<int> queue_binary_tree() {
        std::string s, value;
        std::queue<int> q;
        std::getline(std::cin, s);

        std::istringstream ss{ std::regex_replace(s, std::regex{R"(\[|\]|,)"}, " ") };

        while (ss >> value) {
            if (value == "null") {
                q.push(INT_MIN);
            }
            else {
                q.push(stoi(value));
            }

        }

        return q;
    }

    TreeNode* construct_binary_tree(std::queue<int>& q) {
        TreeNode* root = new TreeNode(q.front());
        q.pop();

        root = recurse_level_order(root, q);

        return root;
    }


};