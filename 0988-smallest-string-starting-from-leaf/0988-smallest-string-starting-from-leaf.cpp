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
    void inOrder(TreeNode* root, string curr, vector<string>& output)
    {
        if (root == nullptr)
        {
            return;
        }

        curr.push_back(root->val + 97);

        if (root->left == nullptr && root->right == nullptr)
        {
            int i = 0;
            int j = curr.length()-1;

            while (i < j)
            {
                swap(curr[i], curr[j]);
                i++;
                j--;
            }

            output.push_back(curr);
        }

        inOrder(root->left, curr, output);

        inOrder(root->right, curr, output);
    }

    string smallestFromLeaf(TreeNode* root) {
        
        vector<string> output;

        inOrder(root, "", output);

        sort(begin(output), end(output));

        return output[0];
    }
};