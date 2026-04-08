class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];
            
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (nums[idx] * (long long)v) % 1000000007;
            }
        }


        int output = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            output ^= nums[i];
        }

        return output;
    }
};