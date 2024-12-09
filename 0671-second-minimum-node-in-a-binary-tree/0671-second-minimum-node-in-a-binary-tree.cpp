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
    void inOrder(TreeNode* root, set<int>& st)
    {
        if (root == nullptr)
        {
            return;
        }

        st.insert(root->val);

        inOrder(root->left, st);

        inOrder(root->right, st);
    }

    int findSecondMinimumValue(TreeNode* root) {
        
        set<int> st;

        inOrder(root, st);

        int i = 0;

        for (auto itr = st.begin(); itr != st.end(); itr++)
        {
            if (i == 1)
            {
                return *itr;
            }
            i++;
        }

        return -1;
    }
};