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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        if (left > right) {
            return left + 1;
        }

        return right + 1;
    }

    void helper(TreeNode* root, int currDepth, int& maxDepth, deque<TreeNode*>& curr, vector<deque<TreeNode*>>& paths) {
        if (root == nullptr) {
            return;
        }

        curr.push_back(root);

        if (currDepth == maxDepth) {
            paths.push_back(curr);
        }

        helper(root->left, currDepth+1, maxDepth, curr, paths);
        helper(root->right, currDepth+1, maxDepth, curr, paths);

        curr.pop_back();
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        int depth = maxDepth(root);
        vector<deque<TreeNode*>> paths;
        deque<TreeNode*> curr;

        helper(root, 1, depth, curr, paths);

        if (paths.size() == 1) {
            return paths[0][paths[0].size()-1];
        }


        TreeNode* prev = root;
        for (int i = 1; i < paths[0].size(); i++) {
            TreeNode* currNode = paths[0][i];
            for (int j = 1; j < paths.size(); j++) {
                if (currNode != paths[j][i]) {
                    return prev;
                }
            }

            prev = currNode;
        }

        return root;
    }
};