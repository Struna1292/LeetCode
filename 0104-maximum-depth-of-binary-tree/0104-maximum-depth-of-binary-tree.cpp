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

    void inOrder(TreeNode* root, int &depth, int &deepest)
    {
        if (root == NULL)
        {
            return;
        }

        depth++;
        if (depth > deepest)
        {
            deepest = depth;
        }
        inOrder(root->left, depth, deepest);
        inOrder(root->right, depth, deepest);
        depth--;
    }
    int maxDepth(TreeNode* root) {
        int depth = 0;
        int deepest = 0;
        inOrder(root, depth, deepest);
        return deepest;
    }
};