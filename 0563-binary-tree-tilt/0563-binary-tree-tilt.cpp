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

        inOrder(root->left, output);

        inOrder(root->right, output);

        if (root->left != nullptr && root->right != nullptr)
        {
            output += abs(root->left->val - root->right->val);
            root->val += root->left->val;
            root->val += root->right->val;
        }
        else if (root->left != nullptr)
        {
            output += abs(root->left->val);
            root->val += root->left->val;
        }
        else if (root->right != nullptr)
        {
            output += abs(root->right->val);
            root->val += root->right->val;
        }
    }

    int findTilt(TreeNode* root) {
        
        int output = 0;

        inOrder(root, output);

        return output;
    }
};