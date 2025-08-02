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
    void DFS(TreeNode* curr, int& targetSum, int currSum, list<int>& currPath, vector<vector<int>>& paths) {
        if (curr == nullptr) {
            return;
        }

        currSum += curr->val;
        currPath.push_back(curr->val);

        if (curr->left == nullptr && curr->right == nullptr && currSum == targetSum) {
            vector<int> curr(currPath.size(), 0);

            int i = 0;
            for (auto itr = currPath.begin(); itr != currPath.end(); itr++) {
                curr[i] = *itr;
                i++;
            }

            paths.push_back(curr);
        }

        DFS(curr->left, targetSum, currSum, currPath, paths);
        DFS(curr->right, targetSum, currSum, currPath, paths);

        currPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> paths;
        list<int> currPath;

        DFS(root, targetSum, 0, currPath, paths);

        return paths;
    }
};