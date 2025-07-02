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
    TreeNode* search(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }

        if (val == root->val) {
            return root;
        }

        if (val < root->val) {
            return search(root->left, val);
        }
        return search(root->right, val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return search(root, val);
    }
};