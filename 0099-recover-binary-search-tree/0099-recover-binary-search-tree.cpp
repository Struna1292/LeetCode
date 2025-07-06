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
    void inOrder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }

        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }

    void fix(TreeNode* root, vector<int>& nums, int& index) {
        if (root == nullptr) {
            return;
        }

        fix(root->left, nums, index);
        root->val = nums[index];
        index++;
        fix(root->right, nums, index);
    }

    void recoverTree(TreeNode* root) {
        // inOrder traversal of Binary Search Tree is always sorted
        vector<int> nums;
        inOrder(root, nums);    
        sort(begin(nums), end(nums));
        int i = 0;
        fix(root, nums, i);
    }
};