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

    bool findTarget(TreeNode* root, int k) {

        vector<int> nums;

        inOrder(root, nums);

        sort(begin(nums), end(nums));

        int i = 0;
        int j = nums.size()-1;

        while (i < j)
        {
            if (nums[i] + nums[j] == k)
            {
                return true;
            }
            else if (nums[i] + nums[j] > k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return false;
    }
};