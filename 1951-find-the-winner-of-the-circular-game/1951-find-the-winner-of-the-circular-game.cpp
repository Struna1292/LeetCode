class Solution {
public:
    int findTheWinner(int n, int k) {
        
        vector<bool> nums(n, true);

        int j = -1;

        for (int i = 0; i < n-1; i++)
        {
            int l = 0;

            while (l < k)
            {
                j++;

                if (j == n)
                {
                    j -= n;
                }

                if (nums[j])
                {
                    l++;
                }
            }

            nums[j] = false;
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i])
            {
                return i+1;
            }
        }

        return -1;
    }
};