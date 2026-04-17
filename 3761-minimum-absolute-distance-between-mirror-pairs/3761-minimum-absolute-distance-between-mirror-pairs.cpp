class Solution {
public:
    int reverseNumber(int num) {
        int reversed = 0;

        while (num != 0) {
            int digit = num % 10;          
            reversed = reversed * 10 + digit; 
            num /= 10;                    
        }

        return reversed;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> reversed;
        unordered_map<int, int> lastIndex;

        int output = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (lastIndex.contains(nums[i])) {
                int distance = i - lastIndex[nums[i]];

                if (output == -1 || output > distance) {
                    output = distance;
                }
            }

            if (!reversed.contains(nums[i])) {
                reversed[nums[i]] = reverseNumber(nums[i]);
            }

            int reversedNum = reversed[nums[i]];
            lastIndex[reversedNum] = i;
        }

        return output;
    }
};