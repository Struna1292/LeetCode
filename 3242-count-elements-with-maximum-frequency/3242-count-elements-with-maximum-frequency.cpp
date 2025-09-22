class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int> um;
        
        int bestCount = 0;
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
            if (um[nums[i]] > bestCount) {
                bestCount = um[nums[i]];
                total = bestCount;
            }
            else if (um[nums[i]] == bestCount) {
                total += bestCount;
            }
        }

        return total;
    }
};