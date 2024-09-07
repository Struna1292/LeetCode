/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void helper(TreeNode* root, int i, vector<int>& nums, bool& output)
    {

        if (i == nums.size())
        {
            output = true;
            return;
        }

        if (root->left != nullptr && root->left->val == nums[i])
        {
            helper(root->left, i+1, nums, output);
        }

        if (root->right != nullptr && root->right->val == nums[i])
        {
            helper(root->right, i+1, nums, output);
        }
    }

    void inOrder(TreeNode* root, vector<int>& nums, bool& output)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->val == nums[0])
        {
            helper(root, 1, nums, output);
        }

        inOrder(root->left, nums, output);

        inOrder(root->right, nums, output);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        
        vector<int> nums;

        while (head != nullptr)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        bool output = false;

        inOrder(root, nums, output);

        return output;
    }
};