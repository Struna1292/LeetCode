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
    void helper(TreeNode* root, vector<int> curr, int& output)
    {
        if (root == nullptr)
        {
            return;
        }

        curr[root->val-1]++;

        if (root->left == nullptr && root->right == nullptr)
        {
            bool palindrome = true;

            bool odd = false;

            for (int i = 0; i < 9; i++)
            {
                if (curr[i] != 0)
                {
                    if (curr[i] % 2 != 0)
                    {
                        if (!odd)
                        {
                            odd = true;
                        }
                        else
                        {
                            palindrome = false;
                            break;
                        }
                    }
                }
            }

            if (palindrome)
            {
                output++;
            }
            return;
        }

        helper(root->left, curr, output);

        helper(root->right, curr, output);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int output = 0;

        vector<int> curr(9, 0);

        helper(root, curr, output);

        return output;
    }
};