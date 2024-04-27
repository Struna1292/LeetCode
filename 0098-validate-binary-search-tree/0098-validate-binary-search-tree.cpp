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
    
    void inOrder(TreeNode* root, vector<int>& nums, bool& output)
    {
        if (root == nullptr || !output)
        {
            return;
        }


        inOrder(root->left, nums, output);

        if (nums.size() >= 1 && root->val <= nums[nums.size()-1])
        {
            output = false;
            return;
        }
        
        nums.push_back(root->val);

        inOrder(root->right, nums, output);
    }

    bool isValidBST(TreeNode* root) {

        bool output = true;

        vector<int> nums;

        inOrder(root, nums, output);
        
        return output;
    }
};