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
    void helperInsert(TreeNode* root, int val) {
        if (root == nullptr) {
            return;
        }

        if (val > root->val && root->right == nullptr) {
            root->right = new TreeNode(val);
            return;
        } else if (val < root->val && root->left == nullptr) {
            root->left = new TreeNode(val);
            return;
        }

        if (val > root->val) {
            helperInsert(root->right, val);
        } else {
            helperInsert(root->left, val);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        helperInsert(root, val);

        return root;
    }
};