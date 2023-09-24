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
    void inOrder(TreeNode* root, string path, vector<string>& output, int &i)
    {
        if (root == nullptr)
        {
            return;
        }

        if (i != 0)
            path += "->";
        path += to_string(root->val);
        
        i++;

        if (root->left == nullptr && root->right == nullptr)
        {
            output.push_back(path);
            return;
        }

        inOrder(root->left, path, output, i);

        inOrder(root->right, path, output, i);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string path;

        vector<string> output;

        int i = 0;

        inOrder(root, path, output, i);

        return output;
    }
};