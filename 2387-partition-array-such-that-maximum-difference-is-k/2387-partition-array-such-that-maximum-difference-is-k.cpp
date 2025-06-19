class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(begin(nums), end(nums));

        int partition = 1;
        int prevMin = nums[0];

        for (int n : nums) {
            if (n-prevMin > k) {
                partition++;
                prevMin = n;
            }
        }

        return partition;
    }
};