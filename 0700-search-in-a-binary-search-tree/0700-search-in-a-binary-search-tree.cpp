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
    TreeNode* searchBST(TreeNode* root, int val) {

        TreeNode* curr = root;

        while (curr != NULL)
        {
            if (curr->val == val)
            {
                return curr;
            }
            else if (curr->val > val)
            {
                if (curr->left != nullptr)
                {
                    curr = curr->left;
                }
                else
                {
                    return NULL;
                }
            }
            else
            {
                if (curr->right != nullptr)
                {
                    curr = curr->right;
                }
                else
                {
                    return NULL;
                }
            }
        }

        return curr;
    }
};