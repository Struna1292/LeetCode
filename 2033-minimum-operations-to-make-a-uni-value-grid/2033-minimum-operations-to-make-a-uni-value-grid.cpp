class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                nums.push_back(grid[i][j]);
            }
        }

        sort(begin(nums), end(nums));

        int median = nums[nums.size() / 2];

        unordered_map<int, int> um;

        int output = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!um.contains(nums[i])) { 
                int diff = abs(nums[i] - median);
                if (diff == 0) {
                    um[nums[i]] = 0;
                }
                else if (diff % x != 0) {
                    return -1;
                }

                um[nums[i]] = diff / x;
            }

            output += um[nums[i]];
        }

        return output;
    }
};