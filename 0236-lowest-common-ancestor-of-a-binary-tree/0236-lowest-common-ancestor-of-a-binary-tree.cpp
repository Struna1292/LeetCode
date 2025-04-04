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
    void printDQ(deque<TreeNode*> dq)
    {
        for (int i = 0; i < dq.size(); i++)
        {
            cout << dq[i]->val << " ";
        }
        cout << endl;
    }

    void helper(TreeNode* root, TreeNode* target, deque<TreeNode*>& dq, bool& found)
    {
        if (root == nullptr || found)
        {
            return;
        }

        dq.push_back(root);

        if (root == target)
        {
            found = true;
            return;
        }

        helper(root->left, target, dq, found);

        helper(root->right, target, dq, found);

        if (!found)
        {
            dq.pop_back();
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // find path to given nodes
        // store it as double ended queue of pointers because we can easily compare both paths, and we dont take extra space in recursion iteration through tree
        // when we iterate through both paths the moment ancestors differ that means previous one is the answer

        deque<TreeNode*> dq1;
        bool found = false;

        helper(root, p, dq1, found);

        deque<TreeNode*> dq2;
        found = false;

        helper(root, q, dq2, found);
        
        TreeNode* prev = root;
        while (!dq1.empty() && !dq2.empty())
        {
            if (dq1.front() != dq2.front())
            {
                break;
            }
            prev = dq1.front();

            dq1.pop_front();
            dq2.pop_front();
        }

        return prev;
    }
};