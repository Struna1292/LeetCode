class Solution {
public:
    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> digitsSum;
        unordered_map<int, int> originalIndex;

        for (int i = 0; i < nums.size(); i++) {
            originalIndex[nums[i]] = i;

            string s = to_string(nums[i]);
            int currSum = 0;
            for (int j = 0; j < s.length(); j++) {
                currSum += s[j] - '0';
            }

            digitsSum[nums[i]] = currSum;
        }

        vector<int> temp = nums;

        sort(begin(temp), end(temp), [&digitsSum](int& a, int& b) {
            if (digitsSum[a] == digitsSum[b]) {
                return a < b;
            }

            return digitsSum[a] < digitsSum[b];
        });

        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != temp[i]) {
                int tempOgIndex = originalIndex[temp[i]];
                originalIndex[nums[i]] = tempOgIndex;
                originalIndex[temp[i]] = i;

                swap(nums[i], nums[tempOgIndex]);

                counter++;
            }
        }

        return counter;
    }
};