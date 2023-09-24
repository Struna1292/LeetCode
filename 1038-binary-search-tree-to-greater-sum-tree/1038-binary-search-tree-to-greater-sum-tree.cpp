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
    void helper(TreeNode* root, int& num)
    {
        if (root == nullptr)
        {
            return;
        }

        helper(root->right, num);

        num += root->val;

        root->val = num;

        helper(root->left, num);
    }

    TreeNode* bstToGst(TreeNode* root) {
        
        int num = 0;

        helper(root, num);

        return root;
    }
};