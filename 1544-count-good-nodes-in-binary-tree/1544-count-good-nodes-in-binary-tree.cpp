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
    void inOrder(TreeNode* root, int curr, int& output)
    {
        if (root == nullptr)
        {
            return;
        }
        
        if (curr <= root->val)
        {
            output++;
            curr = root->val;
        }

        inOrder(root->left, curr, output);

        inOrder(root->right, curr, output);
    }

    int goodNodes(TreeNode* root) {
        
        int output = 0;

        inOrder(root, root->val, output);

        return output;
    }
};