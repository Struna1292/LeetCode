class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, list<int>> um;

        int output = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (um[nums[i]].size() == 2) {
                int first = um[nums[i]].front();
                int second = um[nums[i]].back();
                int third = i;

                int currDistance = abs(first - second) + abs(second - third) + abs(third - first);
                if (output == -1 || output > currDistance) {
                    output = currDistance;
                }

                um[nums[i]].pop_front();
            }

            um[nums[i]].push_back(i);
        }

        return output;      
    }
};