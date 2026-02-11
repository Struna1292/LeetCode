class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int counter = 0;
        float numsCounter = 0;
        float sum = 0;
        for (int i = nums.size()-1; i >= 0; i--) {

            if (numsCounter != 0 && nums[i] > sum / numsCounter) {
                counter++;
            }

            sum += nums[i];
            numsCounter++;
        }

        return counter;
    }
};