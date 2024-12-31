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
    void depth(TreeNode* root, int curr, int& output)
    {
        if (root == nullptr)
        {
            return;
        }

        if (curr > output)
        {
            output = curr;
        }

        depth(root->left, curr+1, output);

        depth(root->right, curr+1, output);
    }

    void inOrder(TreeNode* root, bool& output)
    {
        if (!output || root == nullptr)
        {
            return;
        }

        int leftDepth = 0;
        int rightDepth = 0;

        depth(root->left, 1, leftDepth);
        depth(root->right, 1, rightDepth);

        if (abs(leftDepth - rightDepth) > 1)
        {
            output = false;
            return;
        }

        inOrder(root->left, output);

        inOrder(root->right, output);
    }

    bool isBalanced(TreeNode* root) {

        if (root == nullptr)
        {
            return true;
        }
        
        bool output = true;

        inOrder(root, output);

        return output;
    }
};