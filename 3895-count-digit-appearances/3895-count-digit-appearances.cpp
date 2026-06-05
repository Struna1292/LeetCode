class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        unordered_map<int, int> um;

        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (um.contains(nums[i])) {
                counter += um[nums[i]];
                continue;
            }
            
            int currCounter = 0;
            int currNum = nums[i];

            while (currNum > 0) {
                int currDigit = currNum % 10;
                if (currDigit == digit) {
                    currCounter++;
                }
                currNum /= 10;
            }

            counter += currCounter;
            um[nums[i]] = currCounter;
        }

        return counter;
    }
};