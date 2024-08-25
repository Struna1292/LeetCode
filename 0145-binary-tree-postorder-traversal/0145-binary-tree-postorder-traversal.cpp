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
    void postOrder(TreeNode* root, vector<int>& output)
    {
        if (root == nullptr)
        {
            return;
        }

        postOrder(root->left, output);

        postOrder(root->right, output);

        output.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> output;

        postOrder(root, output);

        return output;
    }
};