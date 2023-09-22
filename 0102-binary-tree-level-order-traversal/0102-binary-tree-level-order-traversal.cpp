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
    void inOrder(TreeNode* root, vector<vector<int>>& output, int i)
    {
        i++;
        if (root == nullptr)
        {
            return;
        }

        if (output.size() < i+1)
        {
            output.push_back({});
        }
        output[i].push_back(root->val);

        inOrder(root->left, output, i);

        inOrder(root->right, output, i);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;

        int i = -1;

        inOrder(root, output, i);

        return output;
    }
};