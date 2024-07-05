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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> nums;

        while (head != nullptr)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        int minDistance = -1;
        int prevIndex = -1;

        int firstIndex = -1;

        for (int i = 1; i < nums.size()-1; i++)
        {
            if ((nums[i] > nums[i-1] && nums[i] > nums[i+1]) || (nums[i] < nums[i-1] && nums[i] < nums[i+1]))
            {
                if (prevIndex != -1)
                {
                    if (minDistance == -1)
                    {
                        minDistance = i-prevIndex;
                    }
                    else
                    {
                        if (i-prevIndex < minDistance)
                        {
                            minDistance = i-prevIndex;
                        }
                    }
                }
                else
                {
                    firstIndex = i;
                }
                prevIndex = i;
            }
        }

        int maxDistance = -1;

        if (firstIndex != -1 && firstIndex != prevIndex)
        {
            maxDistance = prevIndex - firstIndex;
        }

        return {minDistance,maxDistance};
    }
};