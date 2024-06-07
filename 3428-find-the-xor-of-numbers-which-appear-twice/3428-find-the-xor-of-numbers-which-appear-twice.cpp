class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        
        int occs[50] = { 0 };

        for (int i = 0; i < nums.size(); i++)
        {
            occs[nums[i]-1]++;
        }

        int prev = 0;
        int i = 0;

        while (i < 50 && occs[i] != 2)
        {
            i++;
        }

        prev = i+1;
        i++;

        if (prev == 51)
        {
            return 0;
        }

        for (i; i < 50; i++)
        {
            if (occs[i] == 2)
            {
                prev ^= (i+1);
            }
        }

        return prev;
    }
};