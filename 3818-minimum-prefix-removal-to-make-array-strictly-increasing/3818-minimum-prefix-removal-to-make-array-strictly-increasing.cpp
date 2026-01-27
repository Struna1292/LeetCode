class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        
        int counter = 1;
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                counter++;
            }
            else {
                break;
            }

            if (i == 0) {
                return 0;
            }
        }

        return nums.size() - counter;
    }
};