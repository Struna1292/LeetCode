class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zeros = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeros++;
            }
        }

        int counter = 0;
        int i = nums.size()-1;
        while (i >= 0 && zeros > 0) {
            if (nums[i] != 0) {
                counter++;
            }

            zeros--;
            i--;
        }

        return counter;
    }
};