class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        
        int singleDigit = 0;
        int doubleDigit = 0;

        for (int num : nums)
        {
            if (num > 9)
            {
                doubleDigit += num;
            }
            else
            {
                singleDigit += num;
            }
        }

        if (singleDigit == doubleDigit)
        {
            return false;
        }
        return true;
    }
};