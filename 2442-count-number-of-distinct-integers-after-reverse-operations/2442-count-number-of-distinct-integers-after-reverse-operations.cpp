class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length; i++)
        {
            int num = nums[i];
            int reversed = 0;
            while (num > 0)
            {
                reversed += num % 10;
                num /= 10;
                reversed *= 10;
            }
            reversed /= 10;
            nums.push_back(reversed);
        }
        
        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums));

        return nums.size();
    }
};