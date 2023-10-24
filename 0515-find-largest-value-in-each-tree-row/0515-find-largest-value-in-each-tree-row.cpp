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
    void inOrder(TreeNode* root, int depth, vector<int>& output)
    {
        if (root == nullptr)
        {
            return;
        }

        cout << root->val << " " << depth << endl;

        if (output.size() <= depth)
        {
            output.push_back(root->val);
        }
        else
        {
            if (output[depth] < root->val)
            {
                output[depth] = root->val;
            }
        }

        inOrder(root->left, depth+1, output);

        inOrder(root->right, depth+1, output);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> output;

        inOrder(root, 0, output);

        return output;
    }
};