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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (root == nullptr) {
            return {};
        }
        
        vector<vector<int>> output;

        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});

        while (!que.empty()) {

            TreeNode* curr = que.front().first;
            int currDepth = que.front().second;

            if (currDepth == output.size()) {
                output.push_back({});
            }
            output[currDepth].push_back(curr->val);

            if (curr->left != nullptr) {
                que.push({curr->left, currDepth+1});
            }
            if (curr->right != nullptr) {
                que.push({curr->right, currDepth+1});
            }

            que.pop();
        }

        for (int i = 1; i < output.size(); i += 2) {
            int j = 0;
            int k = output[i].size()-1;

            while (j < k) {
                swap(output[i][j], output[i][k]);
                j++;
                k--;
            }
        }

        return output;
    }
};