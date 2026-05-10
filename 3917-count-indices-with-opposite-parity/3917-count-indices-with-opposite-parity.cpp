class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int even = 0;
        int odd = 0;
        
        vector<int> output(nums.size(), 0);
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] % 2 == 0) {
                even++;
                output[i] = odd;
            }
            else {
                odd++;
                output[i] = even;
            }
        }

        return output;
    }
};