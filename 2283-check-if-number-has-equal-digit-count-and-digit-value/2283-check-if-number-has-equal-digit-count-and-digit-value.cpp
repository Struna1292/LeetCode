class Solution {
public:
    bool digitCount(string num) {

        int nums[10] = { 0 };

        for (int i = 0; i < num.length(); i++)
        {
            nums[num[i]-'0']++;
        }

        for (int i = 0; i < num.length(); i++)
        {
            if (nums[i] != num[i]-'0')
            {
                return false;
            }
        }

        return true;
    }
};