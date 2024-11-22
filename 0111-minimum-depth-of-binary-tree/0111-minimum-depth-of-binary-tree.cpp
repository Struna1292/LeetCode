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
    void inOrder(TreeNode* root, int depth, vector<int>& depths)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            depths.push_back(depth);
        }

        inOrder(root->left, depth+1, depths);

        inOrder(root->right, depth+1, depths);
    }

    int minDepth(TreeNode* root) {
        
        if (root == nullptr)
        {
            return 0;
        }

        vector<int> depths;

        inOrder(root, 1, depths);

        int output = depths[0];

        for (int i = 1; i < depths.size(); i++)
        {
            if (depths[i] < output)
            {
                output = depths[i];
            }
        }

        return output;
    }
};