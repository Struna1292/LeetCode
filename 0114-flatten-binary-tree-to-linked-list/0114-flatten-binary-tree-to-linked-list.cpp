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

    void flatten(TreeNode* root) {
        
        vector<int> nums;

        inOrder(root, nums);

        TreeNode *curr = root;

        for (int i = 0; i < nums.size(); i++)
        {
            curr->val = nums[i];
            curr->left = nullptr;

            if (curr->right == nullptr && (i+1) != nums.size())
            {
                curr->right = new TreeNode;
            }
            curr = curr->right;
        }
    }
};