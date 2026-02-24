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
    void DFS(TreeNode* root, int curr, int& output) {
        if (root == nullptr) {
            return;
        } 
        
        curr <<= 1;
        if ((root->val & 1) == 1) {
            curr |= 1;
        }

        if (root->left == nullptr && root->right == nullptr) {
            output += curr;
            return;
        }
        DFS(root->left, curr, output);
        DFS(root->right, curr, output);
    }

    int sumRootToLeaf(TreeNode* root) {     
        int output = 0;

        DFS(root, 0, output);

        return output;
    }
};