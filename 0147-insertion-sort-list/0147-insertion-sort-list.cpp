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
    void insertionSort(vector<int>& nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            int j = i-1;
            int key = nums[i];
            while (j >= 0 && nums[j] > key)
            {
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key;
        }
    }

    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr = head;

        vector<int> nums;
        while (curr != NULL)
        {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        insertionSort(nums);
        
        int i = 0;
        curr = head;
        while (curr != NULL)
        {
            curr->val = nums[i];
            i++;
            curr = curr->next;
        }

        return head;
    }
};