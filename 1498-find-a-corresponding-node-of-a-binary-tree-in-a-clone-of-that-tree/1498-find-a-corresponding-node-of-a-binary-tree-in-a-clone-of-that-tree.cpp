/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void inOrder(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode*& clonedTarget) {
        if (original == nullptr || clonedTarget != nullptr) {
            return;
        }

        if (original == target) {
            clonedTarget = cloned;
            return;
        }

        inOrder(original->left, cloned->left, target, clonedTarget);

        inOrder(original->right, cloned->right, target, clonedTarget);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* clonedTarget = nullptr;

        inOrder(original, cloned, target, clonedTarget);

        return clonedTarget;
    }
};