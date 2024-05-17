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
    void inOrder(TreeNode* root, int& target)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrder(root->left, target);

        inOrder(root->right, target);

        if (root->left != nullptr && root->left->val == target)
        {
            TreeNode* temp = root->left;
            if (temp->left == nullptr && temp->right == nullptr)
            {
                root->left = nullptr;
                delete temp;
            }
        }

        if (root->right != nullptr && root->right->val == target)
        {
            TreeNode* temp = root->right;
            if (temp->left == nullptr && temp->right == nullptr)
            {
                root->right = nullptr;
                delete temp;
            }
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        inOrder(root, target);

        if (root != nullptr && root->val == target && root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
        }

        return root;
    }
};