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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }

        vector<int> nums;

        ListNode* curr = head;
        while (curr != nullptr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        k %= nums.size();

        vector<int> rotated(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            rotated[(i+k) % nums.size()] = nums[i];
        }

        int i = 0;
        curr = head;
        while (curr != nullptr) {
            curr->val = rotated[i];
            curr = curr->next;
            i++;
        }

        return head;
    }
};