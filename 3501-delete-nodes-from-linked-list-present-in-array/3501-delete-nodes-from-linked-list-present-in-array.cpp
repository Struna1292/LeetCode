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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int> us;

        for (int i = 0; i < nums.size(); i++) {
            us.insert(nums[i]);
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            if (us.contains(curr->val)) {
                if (curr == head) {
                    head = head->next;
                    ListNode* temp = curr;
                    curr = head;
                    //delete temp;
                }
                else {
                    ListNode* temp = curr;
                    prev->next = curr->next;
                    curr = prev->next;
                    //delete temp;
                }
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};