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
    void inOrder(TreeNode* root, int currDepth, int& depth, int& value)
    {
        if (root == nullptr || currDepth > depth-1)
        {
            return;
        }


        if (currDepth == depth-1)
        {
            TreeNode* leftContinue = root->left;
            TreeNode* rightContinue = root->right;

            root->left = nullptr;
            root->right = nullptr;

            root->left = new TreeNode;
            root->right = new TreeNode;

            root->left->val = value;
            root->right->val = value; 

            root->left->left = leftContinue;
            root->right->right = rightContinue;
        }

        inOrder(root->left, currDepth+1, depth, value);

        inOrder(root->right, currDepth+1, depth, value);
        
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if (depth == 1)
        {
            TreeNode* head = new TreeNode;
            head->val = val;
            head->left = root;
            root = head;
        }
        else
        {
            inOrder(root, 1, depth, val);
        }



        return root;
    }
};