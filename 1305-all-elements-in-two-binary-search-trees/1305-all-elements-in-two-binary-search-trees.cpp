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
    void inOrder(TreeNode* root, vector<int>& nums)
    {
        if (root == nullptr)
        {
            return;
        }

        nums.push_back(root->val);

        inOrder(root->left, nums);

        inOrder(root->right, nums);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> output;

        inOrder(root1, output);

        inOrder(root2, output);

        sort(begin(output), end(output));

        return output;
    }
};