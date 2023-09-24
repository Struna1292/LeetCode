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
    void helper(TreeNode* root, vector<int>& nums)
    {
        // find max value

        int highest = nums[0];
        int index = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > highest)
            {
                highest = nums[i];
                index = i;
            }
        }

        // set root val to max 

        root->val = highest;

        // make left and right to max value vectors

        vector<int> left;

        for (int i = 0; i < index; i++)
        {
            left.push_back(nums[i]);
        }

        vector<int> right;

        for (int i = index+1; i < nums.size(); i++)
        {
            right.push_back(nums[i]);
        }

        // if vector is not empty keep going to the left with left vector
        if (left.size() != 0)
        {
            root->left = new TreeNode;
            helper(root->left, left);
        }

        // if vector is not empty keep going to the right with right vector
        if (right.size() != 0)
        {
            root->right = new TreeNode;
            helper(root->right, right);
        }

    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        TreeNode* root = new TreeNode;
        
        helper(root, nums);

        return root;
    }
};