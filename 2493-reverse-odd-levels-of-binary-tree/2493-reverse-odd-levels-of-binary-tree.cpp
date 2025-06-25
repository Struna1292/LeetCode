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
    void getLevels(TreeNode* root, int depth, vector<stack<int>>& levels) {
        if (root == nullptr) {
            return;
        }

        if (levels.size() <= depth) {
            levels.push_back(stack<int>());
        }

        if (depth % 2 != 0) {
            levels[depth].push(root->val);
        }

        getLevels(root->left, depth+1, levels);

        getLevels(root->right, depth+1, levels);
    }

    void setLevels(TreeNode* root, int depth, vector<stack<int>>& levels) {
        if (root == nullptr) {
            return;
        }

        if (depth % 2 != 0) {
            root->val = levels[depth].top();
            levels[depth].pop();
        }

        setLevels(root->left, depth+1, levels);

        setLevels(root->right, depth+1, levels);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        
        vector<stack<int>> levels;

        getLevels(root, 0, levels);

        setLevels(root, 0, levels);

        return root;
    }
};