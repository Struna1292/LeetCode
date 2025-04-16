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
    void helper(TreeNode* root, vector<vector<pair<int, TreeNode*>>>& levels, int depth, TreeNode* parent)
    {
        if (root == nullptr)
        {
            return;
        }

        if (levels.size() < depth+1)
        {
            levels.push_back({});
        }

        levels[depth].push_back({root->val, parent});

        helper(root->left, levels, depth+1, root);

        helper(root->right, levels, depth+1, root);
    }

    void setValues(TreeNode* root, vector<vector<pair<int, TreeNode*>>>& levels, int depth, TreeNode* parent)
    {
        if (root == nullptr)
        {
            return;
        }

        int sum = 0;
        for (int i = 0; i < levels[depth].size(); i++)
        {
            if (levels[depth][i].second != parent)
            {
                sum += levels[depth][i].first;
            }
        }

        root->val = sum;

        setValues(root->left, levels, depth+1, root);

        setValues(root->right, levels, depth+1, root);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        
        vector<vector<pair<int, TreeNode*>>> levels; // pair denotes value and parent

        helper(root, levels, 0, nullptr);

        setValues(root, levels, 0, nullptr);

        return root;
    }
};