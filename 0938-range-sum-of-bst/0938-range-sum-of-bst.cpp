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
    void inOrder(TreeNode* curr, int low, int high, int &output)
    {
        if (curr == nullptr)
        {
            return;
        }

        if (curr->val >= low && curr->val <= high)
        {
            output += curr->val;
        }

        inOrder(curr->left, low, high, output);

        inOrder(curr->right, low, high, output);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int output = 0;

        inOrder(root, low, high, output);

        return output;
    }
};