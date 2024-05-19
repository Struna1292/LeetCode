class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {

        long long output = 0;

        int length = to_string(nums[0]).length();

        for (int i = 0; i < length; i++)
        {   
            int curr[10] = { 0 };

            for (int j = 0; j < nums.size(); j++)
            {
                int digit = nums[j] % 10;
                nums[j] /= 10;
                curr[digit]++;
            }

            int total = 0;

            for (int j = 0; j < 10; j++)
            {
                cout << j << " : " << curr[j] << endl;
                if (curr[j] > 0)
                {
                    total += curr[j];
                    output += (nums.size() - total) * curr[j];
                }
            }
        }

        return output;
    }
};