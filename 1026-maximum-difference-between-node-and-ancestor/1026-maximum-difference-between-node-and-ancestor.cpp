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
    void inOrder(TreeNode* root, vector<pair<int,int>>& nums, vector<int>& leaves)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            leaves.push_back(root->val);
        }

        if (root->left != nullptr)
        {
            nums.push_back({root->left->val, root->val});
        }

        if (root->right != nullptr)
        {
            nums.push_back({root->right->val, root->val});
        }

        inOrder(root->left, nums, leaves);

        inOrder(root->right, nums, leaves);


    }

    int maxAncestorDiff(TreeNode* root) {

        int output = 0;

        vector<pair<int,int>> nums = {{root->val, -1}}; //value and parent

        vector<int> leaves;
        
        inOrder(root, nums, leaves);

        for (int i = 0; i < leaves.size(); i++)
        {
            int highest = leaves[i];
            int lowest = leaves[i];

            int curr = leaves[i];
            while (curr != -1)
            {
                for (int j = 0; j < nums.size(); j++)
                {
                    if (nums[j].first == curr)
                    {
                        curr = nums[j].second;
                    }
                }

                if (curr != -1)
                {
                    if (curr > highest)
                    {
                        highest = curr;
                    }

                    if (curr < lowest)
                    {
                        lowest = curr;
                    }
                }
            }

            if (highest - lowest > output)
            {
                output = highest - lowest;
            }
        }

        return output;
    }
};