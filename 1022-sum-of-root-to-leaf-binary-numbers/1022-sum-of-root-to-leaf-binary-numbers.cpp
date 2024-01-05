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
    void helper(TreeNode* root, int curr, int& output)
    {
        if (root == nullptr)
        {
            return;
        }

        curr <<= 1;

        if (root->val == 1)
        {
            curr |= 1;
        }

        helper(root->left, curr, output);

        helper(root->right, curr, output);

        if (root->left == nullptr && root->right == nullptr)
        {
            output += curr;
        }
    }

    int sumRootToLeaf(TreeNode* root) {
        int output = 0;

        helper(root, 0, output);

        return output;
    }
};