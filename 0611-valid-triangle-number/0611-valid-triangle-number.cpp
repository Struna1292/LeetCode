class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        sort(begin(nums), end(nums));
        int output = 0;

        for (int index = nums.size()-1; index >= 2; index--) {
            int i = 0;
            int j = index-1;

            while (i < j) {
                if (nums[i] + nums[j] > nums[index]) {
                    output += (j - i);
                    j--;
                }
                else {
                    i++;
                }
            }
        }

        return output;
    }
};