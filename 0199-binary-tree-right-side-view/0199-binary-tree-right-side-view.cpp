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
    void helper(TreeNode* root, vector<vector<int>>& levels, int depth)
    {
        if (root == nullptr)
        {
            return;
        }

        if (levels.size() < depth)
        {
            levels.push_back({});
        }

        levels[depth-1].push_back(root->val);

        helper(root->left, levels, depth+1);

        helper(root->right, levels, depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        
        vector<vector<int>> levels;

        helper(root, levels, 1);

        vector<int> output;

        for (int i = 0; i < levels.size(); i++)
        {
            output.push_back(levels[i][levels[i].size()-1]);
        }

        return output;
    }
};