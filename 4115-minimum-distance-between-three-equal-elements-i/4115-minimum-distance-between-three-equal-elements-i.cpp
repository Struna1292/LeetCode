class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        unordered_map<int, vector<int>> um;

        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]].push_back(i);
        }

        int output = -1;

        for (auto itr = um.begin(); itr != um.end(); itr++) {
            vector<int> curr = itr->second;

            for (int i = 2; i < curr.size(); i++) {
                if (output == -1) {
                    output = abs(curr[i-2] - curr[i-1]) + abs(curr[i-1] - curr[i]) + abs(curr[i] - curr[i-2]);
                }
                else {
                    output = min(output, abs(curr[i-2] - curr[i-1]) + abs(curr[i-1] - curr[i]) + abs(curr[i] - curr[i-2]));
                }
            }
        }

        return output;
    }
};