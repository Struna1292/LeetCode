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
    void inOrder(TreeNode* root, int check, bool& isUnival)
    {
        if (root == nullptr || !isUnival)
        {
            return;
        }

        if (root->val != check)
        {
            isUnival = false;
        }

        inOrder(root->left, check, isUnival);

        inOrder(root->right, check, isUnival);
    }

    bool isUnivalTree(TreeNode* root) {
        
        bool isUnival = true;

        inOrder(root, root->val, isUnival);

        return isUnival;
    }   
};