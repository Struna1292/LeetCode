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
    void preOrder(TreeNode* root, string& s)
    {
        if (root == nullptr)
        {
            return;
        }

        s += to_string(root->val);

        if (root->left != nullptr || root->right != nullptr)
        {
            s += "(";
            preOrder(root->left, s);
            s += ")";
        }

        if (root->right != nullptr)
        {
            s += "(";
            preOrder(root->right, s);
            s += ")";
        }
    }

    string tree2str(TreeNode* root) {
        string output = "";

        preOrder(root, output);

        return output;
    }
};