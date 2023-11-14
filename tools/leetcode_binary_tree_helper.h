#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <regex>
#include <climits>

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
    TreeNode* recurse_level_order(std::queue<int>& q) {
        if (q.empty()) return nullptr;

        int front = q.front();
        q.pop();

        if (front == INT_MIN) return nullptr;

        TreeNode* node = new TreeNode(front);
        node->left = recurse_level_order(q);
        node->right = recurse_level_order(q);

        return node;
    }

public:
    std::queue<std::string> queue_binary_tree() {
        std::string s, value;
        std::queue<std::string> q;
        std::getline(std::cin, s);

        std::istringstream ss{ std::regex_replace(s, std::regex{R"(\[|\]|,)"}, " ") };

        while (ss >> value) {
            q.push(value);

        }

        return q;
    }


    TreeNode* construct_binary_tree(std::queue<std::string>& q) {
        if (q.empty()) return nullptr;

        TreeNode* root = new TreeNode(stoi(q.front()));
        q.pop();


        // start a bfs
        std::queue<TreeNode*> nodes;        
        nodes.push(root);

        while (!q.empty()) {
            TreeNode* node = nodes.front();
            nodes.pop();

            // process the left node.
            if (!q.empty()) {
                std::string leftVal = q.front();
                q.pop();
                if (leftVal != "null") {
                    node->left = new TreeNode(stoi(leftVal));
                    nodes.push(node->left);
                }
            }

            // process the right node.
            if (!q.empty()) {
                std::string rightVal = q.front();
                q.pop();
                if (rightVal != "null") {
                    node->right = new TreeNode(stoi(rightVal));
                    nodes.push(node->right);
                }
            }
        }

        return root;
    }
};