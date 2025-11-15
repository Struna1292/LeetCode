class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
        }

        int output = 0;
        for (auto itr = um.begin(); itr != um.end(); itr++) {
            if (itr->second % k == 0) {
                output += itr->first * itr->second;
            }
        }

        return output;
    }
};