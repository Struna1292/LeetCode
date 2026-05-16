class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long ascSum = 0;
        int i = 1;
        for (; i < nums.size() && nums[i] > nums[i-1]; i++) {
            ascSum += nums[i-1];
        }

        long long descSum = 0;
        for (; i < nums.size(); i++) {
            descSum += nums[i];
        }

        if (ascSum > descSum) {
            return 0;
        }
        else if (descSum > ascSum) {
            return 1;
        }
        
        return -1;
    }
};