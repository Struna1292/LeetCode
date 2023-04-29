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

    void inOrder(TreeNode* root, int &depth, vector<pair<int,int>> &nums, int &deepest)
    {
        if (root == NULL)
        {
            return;
        }

        depth++;
        if (depth > deepest)
        {
            deepest = depth;
        }

        inOrder(root->left, depth, nums, deepest);

        nums.push_back({root->val, depth});

        inOrder(root->right, depth, nums, deepest);
        depth--;
    }

    int deepestLeavesSum(TreeNode* root) {
        int depth = 0;
        int deepest = 0;
        vector<pair<int,int>> nums; // number and depth
        inOrder(root, depth, nums, deepest);
        
        int deepSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i].second == deepest)
            {
                deepSum += nums[i].first;
            }
        }

        return deepSum;
    }
};