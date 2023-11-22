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
    void insertBST(TreeNode* root, int val)
    {
        TreeNode* prev = root;
        while (root != nullptr)
        {
            prev = root;
            if (root->val < val)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }

        if (prev->val < val)
        {
            prev->right = new TreeNode;
            prev->right->val = val;
        }
        else
        {
            prev->left = new TreeNode;
            prev->left->val = val;
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root = new TreeNode;
        root->val = preorder[0];

        for (int i = 1; i < preorder.size(); i++)
        {
            insertBST(root, preorder[i]);
        }

        return root;
    }
};