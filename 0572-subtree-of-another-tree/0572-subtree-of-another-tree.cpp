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
    void helper(TreeNode* root, TreeNode* subRoot, bool& isMatching)
    {
        if ((root == nullptr && subRoot != nullptr) || (root != nullptr && subRoot == nullptr))
        {
            isMatching = false;
            return;
        }

        if (root == nullptr && subRoot == nullptr)
        {
            return;
        }

        if (root->val != subRoot->val)
        {
            isMatching = false;
            return;
        }

        helper(root->left, subRoot->left, isMatching);

        helper(root->right, subRoot->right, isMatching);
    }   

    void inOrder(TreeNode* root, TreeNode* subRoot, bool& output)
    {
        if (root == nullptr || output)
        {
            return;
        }

        bool check = true;

        helper(root, subRoot, check);

        if (check)
        {
            output = true;
            return;
        }

        inOrder(root->left, subRoot, output);

        inOrder(root->right, subRoot, output);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        bool output = false;

        inOrder(root, subRoot, output);

        return output;
    }
};