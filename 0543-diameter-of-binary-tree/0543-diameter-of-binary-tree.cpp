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
    void getDepth(TreeNode* root, int currDepth, int& depth)
    {
        if (root == nullptr)
        {
            return;
        }

        if (currDepth > depth)
        {
            depth = currDepth;
        }

        getDepth(root->left, currDepth+1, depth);

        getDepth(root->right, currDepth+1, depth);
    }

    void helper(TreeNode* root, int& output)
    {
        if (root == nullptr)
        {
            return;
        }

        int left = 0;
        int right = 0;

        getDepth(root->left, 1, left);
        getDepth(root->right, 1, right);

        if (output < left+right)
        {
            output = left+right;
        }

        helper(root->left, output);

        helper(root->right, output);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        int output = 0;

        helper(root, output);

        return output;
    }
};