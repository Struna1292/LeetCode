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
    void treeSum(TreeNode* root, int& sum) {
        if (root == nullptr) { 
            return; 
        }

        sum += root->val;

        treeSum(root->left, sum);

        treeSum(root->right, sum);
    }

    int DFS(TreeNode* root, int& total, long long& output) {
        if (root == nullptr) {
            return 0;
        }

        long long left = DFS(root->left, total, output);

        long long right = DFS(root->right, total, output);

        long long leftScore = (total - left) * left;
        if (leftScore > output) {
            output = leftScore;
        }

        long long rightScore = (total - right) * right;
        if (rightScore > output) {
            output = rightScore;
        }

        return left + right + root->val;
    }

    int maxProduct(TreeNode* root) {
        
        int total = 0;
        treeSum(root, total);

        long long output = 0;
        DFS(root, total, output);

        return output % 1000000007;
    }
};