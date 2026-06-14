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
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;

        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }

        int output = 0;

        int i = 0;
        int j = nums.size()-1;
        while (i < j) {
            output = max(output, nums[i] + nums[j]);

            i++;
            j--;
        }

        return output;
    }
};