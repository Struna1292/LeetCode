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
    void inOrder(TreeNode* root, int depth, int& output, int& outputDepth)
    {
        if (root == nullptr)
        {
            return;
        }

        depth++;

        if (depth > outputDepth)
        {
            output = root->val;
            outputDepth = depth;
        }

        inOrder(root->left, depth, output, outputDepth);

        inOrder(root->right, depth, output, outputDepth);
    }

    int findBottomLeftValue(TreeNode* root) {
        
        int output = root->val;

        int outputDepth = 1;

        inOrder(root, 0, output, outputDepth);

        return output;
    }
};