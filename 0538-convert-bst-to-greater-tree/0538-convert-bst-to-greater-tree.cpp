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
    void DFS(TreeNode* root, int& curr) {
        if (root == nullptr) {
            return;
        }

        DFS(root->right, curr);
        curr += root->val;
        root->val = curr;
        DFS(root->left, curr);
    }

    TreeNode* convertBST(TreeNode* root) {
        int curr = 0;
        DFS(root, curr);
        return root;
    }
};