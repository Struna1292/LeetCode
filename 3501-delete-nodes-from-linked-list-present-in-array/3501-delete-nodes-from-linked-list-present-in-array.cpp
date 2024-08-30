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
    bool binarySearch(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        sort(begin(nums), end(nums));

        ListNode* list = new ListNode;

        ListNode* curr = list;

        ListNode* prev = nullptr;

        while (head != nullptr)
        {
            ListNode* temp = head;

            if (!binarySearch(nums, head->val))
            {
                curr->val = head->val;
                curr->next = new ListNode;
                prev = curr;
                curr = curr->next;
            }

            head = head->next;
            delete temp;
        }

        prev->next = nullptr;
        
        delete curr;

        return list;
    }
};