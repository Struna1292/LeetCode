/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int DFS(TreeNode* root, bool& output) {
        if (root == nullptr) {
            return 0;
        }

        int left = DFS(root->left, output);
        int right = DFS(root->right, output);

        if (abs(left - right) >= 2) {
            output = false;
        }

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool output = true;

        DFS(root, output);

        return output;
    }
};