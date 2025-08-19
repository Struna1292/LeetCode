class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int counter = 0;
        long long totalSubarrays = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                counter++;
            }
            else {
                for (int j = 1; j <= counter; j++) {
                    totalSubarrays += j;
                }

                counter = 0;
            }
        }

        if (counter != 0) {
            for (int j = 1; j <= counter; j++) {
                totalSubarrays += j;
            }
        }
        return totalSubarrays;
    }
};