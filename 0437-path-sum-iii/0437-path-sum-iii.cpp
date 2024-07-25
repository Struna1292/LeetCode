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
    void inOrder(TreeNode* root, int& targetSum, vector<long> curr, int& output)
    {
        if (root == nullptr)
        {
            return;
        }

        for (int i = 0; i < curr.size(); i++)
        {

            curr[i] += root->val;

            if (curr[i] == targetSum)
            {
                output++;
            }
        }

        curr.push_back(root->val);

        if (root->val == targetSum)
        {
            output++;
        }

        inOrder(root->left, targetSum, curr, output);

        inOrder(root->right, targetSum, curr, output);
    }

    int pathSum(TreeNode* root, int targetSum) {
        
        int output = 0;

        inOrder(root, targetSum, {}, output);

        return output;
    }
};