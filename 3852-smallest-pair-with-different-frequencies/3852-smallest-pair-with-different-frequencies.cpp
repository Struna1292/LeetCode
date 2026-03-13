class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int, int> um;

        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
        }
        
        for (auto itr = um.begin(); itr != um.end(); itr++) {
            for (auto itr2 = itr; itr2 != um.end(); itr2++) {
                if (itr->second != itr2->second) {
                    return {itr->first, itr2->first};
                }
            }
        }

        return {-1, -1};
    }
};