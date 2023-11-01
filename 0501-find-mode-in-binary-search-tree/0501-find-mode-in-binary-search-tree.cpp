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

    vector<int> findMode(TreeNode* root) {

        vector<int> nums;

        inOrder(root, nums);

        sort(begin(nums), end(nums));

        vector<pair<int,int>> occurences;

        int prev = nums[0];
        int counter = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != prev)
            {
                occurences.push_back({counter, prev});
                counter = 1;
                prev = nums[i];
            }
            else
            {
                counter++;
            }
        }

        occurences.push_back({counter, prev});

        sort(begin(occurences), end(occurences));

        int mode = occurences[occurences.size()-1].first;

        vector<int> output;

        int i = occurences.size()-1;

        while (i >= 0 && occurences[i].first == mode)
        {
            output.push_back(occurences[i].second);
            i--;
        }


        
        return output;
    }
};