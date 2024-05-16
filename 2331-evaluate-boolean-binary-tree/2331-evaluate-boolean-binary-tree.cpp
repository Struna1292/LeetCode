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
    void inOrder(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrder(root->left);

        inOrder(root->right);

                if (root->left != nullptr && root->right != nullptr && (root->left->val == 0 || root->left->val == 1) && (root->right->val == 0 || root->right->val == 1))
        {
            if (root->val == 2) // OR
            {
                if (root->left->val == 1 || root->right->val == 1)
                {
                    root->val = 1;
                }
                else
                {
                    root->val = 0;
                }
            }
            else // AND
            {
                if (root->left->val == 1 && root->right->val == 1)
                {
                    root->val = 1;
                }
                else
                {
                    root->val = 0;
                }
            }   
        }
    }

    bool evaluateTree(TreeNode* root) {
        
        inOrder(root);

        return root->val;
    }
};