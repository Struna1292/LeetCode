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
    void findGrandChild(TreeNode* root, int& output)
    {
        if (root->left != nullptr)
        {
            if (root->left->left != nullptr)
                output += root->left->left->val;
            if (root->left->right != nullptr)
                output += root->left->right->val;
        }

        if (root->right != nullptr)
        {
            if (root->right->left != nullptr)
                output += root->right->left->val;
            if (root->right->right != nullptr)
                output += root->right->right->val;
        }
    }

    void inOrder(TreeNode* root, int& output)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->val % 2 == 0)
        {
            findGrandChild(root, output);
        }

        inOrder(root->left, output);

        inOrder(root->right, output);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int output = 0;

        inOrder(root, output);

        return output;
    }
};