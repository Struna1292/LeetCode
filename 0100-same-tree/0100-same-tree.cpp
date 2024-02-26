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

    void inOrder(TreeNode* p, TreeNode* q, bool& output)
    {
        if (p == nullptr && q == nullptr)
        {
            return;
        }
        else if (p != nullptr && q == nullptr || p == nullptr && q != nullptr || p->val != q->val)
        {
            output = false;
            return;
        }

        inOrder(p->left, q->left, output);

        inOrder(p->right, q->right, output);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        bool output = true;

        inOrder(p, q, output);

        return output;
    }
};