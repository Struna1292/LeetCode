class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        vector<int> prefix(nums.size()+1, 0);
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                counter++;
            }

            prefix[i+1] = counter;
        }
 
        int output = counter;

        for (int length = nums.size(); length > 1; length--) {
            for (int i = 0; i+length-1 < nums.size(); i++) {
                int end = i+length;

                int targetCount = prefix[end] - prefix[i];
                if (targetCount > length/2) {
                    output++;
                }
            }
        }

        return output;
    }
};