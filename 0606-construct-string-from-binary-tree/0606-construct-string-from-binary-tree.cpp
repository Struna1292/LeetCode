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
    void inOrder(TreeNode* root, string& s)
    {
        if (root == nullptr)
        {
            return;
        }

        string num = to_string(root->val);

        for (int i = 0; i < num.length(); i++)
        {
            s.push_back(num[i]);
        }
        
        if (root->left != nullptr || root->right != nullptr)
        {
            s.push_back('(');

            inOrder(root->left, s);

            s.push_back(')');
        }

        if (root->right != nullptr)
        {
            s.push_back('(');

            inOrder(root->right, s);

            s.push_back(')');
        }
    }

    string tree2str(TreeNode* root) {
        string output;

        inOrder(root, output);

        return output;
    }
};