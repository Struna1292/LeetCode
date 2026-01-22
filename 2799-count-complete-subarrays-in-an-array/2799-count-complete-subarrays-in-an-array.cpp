class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
        }

        int output = 0;
        int startIndex = 0;
        unordered_map<int, int> currNums;
        for (int i = 0; i < nums.size(); i++) {
            currNums[nums[i]]++;

            while (currNums.size() == um.size()) {
                output += nums.size() - i;

                currNums[nums[startIndex]]--;
                if (currNums[nums[startIndex]] <= 0) {
                    currNums.erase(nums[startIndex]);
                }
                startIndex++;
            }
        }

        return output;
    }
};