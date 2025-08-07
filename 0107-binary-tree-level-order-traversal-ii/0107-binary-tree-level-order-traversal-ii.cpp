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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> que;
        que.push(root);

        vector<vector<int>> levels;

        while (!que.empty()) {

            int count = que.size();
            vector<int> currLevel;

            while (count > 0) {
                TreeNode* curr = que.front();
                que.pop();

                currLevel.push_back(curr->val);

                if (curr->left != nullptr) {
                    que.push(curr->left);
                }
                if (curr->right != nullptr) {
                    que.push(curr->right);
                }
                count--;
            }

            levels.push_back(currLevel);
        }

        int i = 0;
        int j = levels.size()-1;
        while (i < j) {
            swap(levels[i], levels[j]);
            i++;
            j--;
        }

        return levels;
    }
};