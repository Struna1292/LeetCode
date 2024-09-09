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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<int> nums((m * n), -1);

        ListNode* curr = head;
        int j = 0;
        while (curr != NULL)
        {
            nums[j] = curr->val;
            curr = curr->next;
            j++;
        }
      
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int r1 = 0;
        int r2 = m;
        int c1 = 0;
        int c2 = n;

        j = 0;
        while (c1 < c2 && r1 < r2)
        {
            for (int i = c1; i < c2; i++)
            {
                matrix[r1][i] = nums[j];
                j++;
            }
            r1++;

            for (int i = r1; i < r2; i++)
            {
                matrix[i][c2-1] = nums[j];
                j++;
            }
            c2--;

            if (r1 < r2)
            {
                for (int i = c2-1; i >= c1; i--)
                {
                    matrix[r2-1][i] = nums[j];
                    j++;
                }
                r2--;
            }

            if (c1 < c2)
            {
                for (int i = r2-1; i >= r1; i--)
                {
                    matrix[i][c1] = nums[j];
                    j++;
                }
                c1++;
            }

        }

        return matrix;
    }
};