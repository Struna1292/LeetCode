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

    int minDiffInBST(TreeNode* root) {
        
        vector<int> nums;

        inOrder(root, nums);

        sort(begin(nums), end(nums));

        int minDiff = nums[1] - nums[0];

        for (int i = 2; i < nums.size(); i++)
        {
            if (minDiff > nums[i] - nums[i-1])
            {
                minDiff = nums[i] - nums[i-1];
            }
        }

        return minDiff;
    }
};