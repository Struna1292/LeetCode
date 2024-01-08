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
    void helper(TreeNode* root, int low, int high, int& output)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->val >= low && root->val <= high)
        {
            output += root->val;
        }

        helper(root->left, low, high, output);

        helper(root->right, low, high, output);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int output = 0;

        helper(root, low, high, output);

        return output;
    }
};