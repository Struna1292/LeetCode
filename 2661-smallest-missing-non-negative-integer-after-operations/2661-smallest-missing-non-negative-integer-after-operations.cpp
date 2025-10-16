class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); i++) {
            int remainder = nums[i] % value;

            if (nums[i] < 0 && remainder != 0) {
                remainder += value;
            }

            if (um.contains(remainder)) {
                um[remainder] += value;
            }
            else {
                um[remainder] = remainder;
            }
        }

        for (int i = 0; i < value; i++) {
            if (um.contains(i)) {
                um[i] += value;
            }
            else {
                um[i] = i;
            }
        }

        int currMin = INT_MAX;
        for (auto itr = um.begin(); itr != um.end(); itr++) {
            currMin = min(currMin, itr->second);
        }

        return currMin;
    }
};