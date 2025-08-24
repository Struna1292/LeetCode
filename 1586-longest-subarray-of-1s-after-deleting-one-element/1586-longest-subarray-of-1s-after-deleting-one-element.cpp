class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int longest = 0;
        int currCounter = 0;
        bool hasZero = false;
        int startIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currCounter++;

                if (currCounter > longest) {
                    longest = currCounter;
                }
            }
            else {
                if (hasZero) {
                    while (nums[startIndex] != 0) {
                        startIndex++;
                        currCounter--;
                    }
                    startIndex++;

                }
                else {
                    hasZero = true;
                }
            }
        }

        if (longest == nums.size()) {
            longest--;
        }
        
        return longest;
    }
};