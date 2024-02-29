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
    void inOrder(TreeNode* root, int depth, vector<vector<int>>& levels, bool& check)
    {
        if (root == nullptr)
        {
            return;
        }

        if (levels.size() < depth+1)
        {
            levels.push_back({});
        }

        if (root->val % 2 == 0 && depth % 2 == 0 || root->val % 2 == 0 && depth % 2 == 0 || root->val % 2 != 0 && depth % 2 != 0)
        {
            check = false;
        }

        levels[depth].push_back(root->val);

        inOrder(root->left, depth+1, levels, check);

        inOrder(root->right, depth+1, levels, check);
    }

    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> levels; 

        bool check = true;

        inOrder(root, 0, levels, check);

        if (!check)
        {
            return false;
        }

        for (int i = 0; i < levels.size(); i++)
        {
            
            for (int j = 1; j < levels[i].size(); j++)
            {
                
                if (i == 0 || i % 2 == 0)
                {
                    if (levels[i][j] <= levels[i][j-1])
                    {
                        return false;
                    }
                }
                else
                {
                    if (levels[i][j] >= levels[i][j-1])
                    {
                        return false;
                    }
                }
            }
            
        }

        return true;
    }
};