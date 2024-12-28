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
    void inOrder(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& pq)
    {
        if (root == nullptr)
        {
            return;
        }

        pq.push(root->val);

        inOrder(root->left, pq);

        inOrder(root->right, pq);
    }


    TreeNode* increasingBST(TreeNode* root) {
        priority_queue<int, vector<int>, greater<int>> pq; 

        inOrder(root, pq);

        TreeNode* head = new TreeNode(pq.top());
        pq.pop();
        TreeNode* curr = head;
        
        while (!pq.empty())
        {
            curr->right = new TreeNode(pq.top());
            pq.pop();
            curr = curr->right;
        }

        return head;
    }
};