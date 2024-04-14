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
    void inOrder(TreeNode* root, int& output)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        {
            output += root->left->val;
        }

        inOrder(root->left, output);

        inOrder(root->right, output);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        
        int output = 0;

        inOrder(root, output);

        return output;
    }
};