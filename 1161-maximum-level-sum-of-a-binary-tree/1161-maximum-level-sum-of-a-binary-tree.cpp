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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> que;
        que.push(root);

        int bestSum = INT_MIN;
        int bestLevel = -1;
        int currLevel = 1;

        while (!que.empty()) {
            
            int size = que.size();
            int currSum = 0;
            while (size > 0) {
                TreeNode* curr = que.front();
                que.pop();
                currSum += curr->val;

                if (curr->left != nullptr) {
                    que.push(curr->left);
                }
                if (curr->right != nullptr) {
                    que.push(curr->right);
                }

                size--;
            }

            if (currSum > bestSum) {
                bestSum = currSum;
                bestLevel = currLevel;
            }
            
            currLevel++;
        }

        return bestLevel;
    }
};