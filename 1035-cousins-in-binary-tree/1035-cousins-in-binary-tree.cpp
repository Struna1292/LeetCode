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
    void inOrder(TreeNode* root, int depth, int currParent, int& x, int& y, int& xParent, int& yParent, int& xDepth, int& yDepth)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->val == x)
        {
            xParent = currParent;
            xDepth = depth;
        }

        if (root->val == y)
        {
            yParent = currParent;
            yDepth = depth;
        }

        inOrder(root->left, depth+1, root->val, x, y, xParent, yParent, xDepth, yDepth);

        inOrder(root->right, depth+1, root->val, x, y, xParent, yParent, xDepth, yDepth);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        
        int xParent = 0;
        int yParent = 0;
        int xDepth = 0;
        int yDepth = 0;

        inOrder(root, 0, 0, x, y, xParent, yParent, xDepth, yDepth);

        if (xParent != yParent && xDepth == yDepth)
        {
            return true;
        }

        return false;
    }
};