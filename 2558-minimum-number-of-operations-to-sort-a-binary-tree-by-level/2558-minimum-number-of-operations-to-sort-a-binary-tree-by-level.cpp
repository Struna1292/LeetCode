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

    int minimumOperations(TreeNode* root) {
        
        vector<vector<int>> nums;

        inOrder(root, 1, nums);

        int output = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> curr = nums[i];

            for (int i = 0; i < curr.size()-1; i++)
            {
                int currMin = curr[i];
                int currIndex = i;
                for (int j = i+1; j < curr.size(); j++)
                {
                    if (curr[j] < currMin)
                    {
                        currMin = curr[j];
                        currIndex = j;
                    }
                }

                if (curr[i] != currMin)
                {
                    output++;

                    swap(curr[i], curr[currIndex]);
                }
            }

        }

        return output;
    }
};