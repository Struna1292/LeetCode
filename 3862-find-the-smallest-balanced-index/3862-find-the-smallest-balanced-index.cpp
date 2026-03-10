class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        
        vector<long double> prefix(nums.size()+1, 0);
        long double currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            prefix[i+1] = currSum;
        }


        long double product = 1;
        int smallestIndex = -1;

        for (int i = nums.size()-1; i >= 0; i--) {
            if (prefix[i] == product) {
                smallestIndex = i;
            }

            product *= nums[i];
        }

        return smallestIndex;
    }
};