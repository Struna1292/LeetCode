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
    void average(TreeNode* root, int& currSum, int& nodesNumber)
    {
        if (root == nullptr)
        {
            return;
        }

        currSum += root->val;
        nodesNumber++;

        average(root->left, currSum, nodesNumber);

        average(root->right, currSum, nodesNumber);
    }

    void inOrder(TreeNode* root, int& output)
    {
        if (root == nullptr)
        {
            return;
        }

        int currSum = 0;
        int nodesNumber = 0;

        average(root, currSum, nodesNumber);

        if (currSum / nodesNumber == root->val)
        {
            output++;
        }

        inOrder(root->left, output);

        inOrder(root->right, output);
    }

    int averageOfSubtree(TreeNode* root) {
        int output = 0;
        
        inOrder(root, output);

        return output;
    }
};