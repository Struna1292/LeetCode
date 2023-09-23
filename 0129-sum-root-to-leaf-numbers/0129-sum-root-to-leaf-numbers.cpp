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
    void inOrder(TreeNode* root, string num, int& output)
    {
        if (root == nullptr)
        {
            return;
        }

        num.push_back(root->val + '0');

        if (root->left == nullptr && root->right == nullptr)
        {
            output += stoi(num);
            return;
        }

        inOrder(root->left, num, output);

        inOrder(root->right, num, output);
    }

    int sumNumbers(TreeNode* root) {

        string num;
        int output = 0;

        inOrder(root, num, output);

        return output;
    }
};