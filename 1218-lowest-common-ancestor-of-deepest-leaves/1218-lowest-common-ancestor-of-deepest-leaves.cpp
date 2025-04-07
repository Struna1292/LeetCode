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
    void pathsToLeafs(TreeNode* root, int depth, int& maxDepth, deque<TreeNode*>& dq, vector<vector<TreeNode*>>& vec)
    {
        if (root == nullptr)
        {
            return;
        }

        dq.push_back(root);

        if (depth > maxDepth)
        {
            maxDepth = depth;
            vec = {};
        }

        if (depth == maxDepth)
        {
            vector<TreeNode*> curr(dq.size(), nullptr);

            for (int i = 0; i < dq.size(); i++)
            {
                curr[i] = dq[i];
            }

            vec.push_back(curr);
        }

        pathsToLeafs(root->left, depth+1, maxDepth, dq, vec);

        pathsToLeafs(root->right, depth+1, maxDepth, dq, vec);

        dq.pop_back();
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        // iterate through tree collecting every path in deque
        // add paths to vector of paths when the depth match current maxDepth
        // when depths is greater than previous maxDepth vector of paths is set to empty

        vector<vector<TreeNode*>> vec;
        deque<TreeNode*> dq;
        int depth = 0;

        pathsToLeafs(root, 1, depth, dq, vec);

        // when there is only one leaf return pointer to him
        if (vec.size() == 1)
        {
            return vec[0][vec[0].size()-1];
        }

        // iterate through paths to every leaf
        // when there is difference in paths that means previous node was lowest common ancestor
        for (int i = 1; i < vec[0].size(); i++)
        {
            TreeNode* prevNode = vec[0][i];
            for (int j = 1; j < vec.size(); j++)
            {
                if (vec[j][i] != prevNode)
                {
                    return vec[j][i-1];
                }

                prevNode = vec[j][i];
            }
        }

        return root;
    }
};