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

    void inOrder(TreeNode* root, int depth, vector<vector<int>>& nums)
    {
        if (root == nullptr)
        {
            return;
        }

        if (nums.size() < depth)
        {
            nums.push_back({});
        }

        nums[depth-1].push_back(root->val);

        inOrder(root->left, depth+1, nums);

        inOrder(root->right, depth+1, nums);
    }

    vector<int> largestValues(TreeNode* root) {
        
        vector<vector<int>> nums;

        inOrder(root, 1, nums);

        vector<int> output;

        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i][0];
            for (int j = 1; j < nums[i].size(); j++)
            {
                if (curr < nums[i][j])
                {
                    curr = nums[i][j];
                }
            }
            output.push_back(curr);
        }

        return output;
    }
};