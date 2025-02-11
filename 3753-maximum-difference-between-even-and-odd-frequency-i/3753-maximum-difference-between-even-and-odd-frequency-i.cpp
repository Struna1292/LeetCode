class Solution {
public:
    int maxDifference(string s) {
        
        int nums[26] = { 0 };

        for (char c : s)
        {
            nums[c-'a']++;
        }

        int minOdd = 0;
        int maxOdd = 0;

        int minEven = 0;
        int maxEven = 0;

        for (int i = 0; i < 26; i++)
        {
            if (nums[i] >= 1)
            {
                if (nums[i] % 2 != 0)
                {
                    if (minOdd == 0 || minOdd < nums[i])
                    {
                        minOdd = nums[i];
                    }
                    if (maxOdd == 0 || maxOdd > nums[i])
                    {
                        maxOdd = nums[i];
                    }
                }
                else
                {
                    if (minEven == 0 || minEven < nums[i])
                    {
                        minEven = nums[i];
                    }
                    if (maxEven == 0 || maxEven > nums[i])
                    {
                        maxEven = nums[i];
                    }
                }
            }
        }

        return max(minOdd-maxEven, maxOdd-minEven);
    }
};