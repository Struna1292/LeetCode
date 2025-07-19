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
    void DFS(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        DFS(root->left);
        DFS(root->right);

        if (root->left != nullptr) {
            TreeNode* temp = root->left;
            if (temp->left == nullptr && temp->right == nullptr && temp->val == 0) {
                root->left = nullptr;
                delete temp;
            }   
        }

        if (root->right != nullptr) {
            TreeNode* temp = root->right;
            if (temp->left == nullptr && temp->right == nullptr && temp->val == 0) {
                root->right = nullptr;
                delete temp;
            }   
        }   
    }

    TreeNode* pruneTree(TreeNode* root) {
        DFS(root);

        if (root->val == 0 && root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }

        return root;
    }
};