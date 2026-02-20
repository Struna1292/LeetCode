class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> numsFreq;
        for (int i = 0; i < nums.size(); i++) {
            numsFreq[nums[i]]++;
        }

        unordered_map<int, int> freq;
        for (auto itr = numsFreq.begin(); itr != numsFreq.end(); itr++) {
            freq[itr->second]++;
        }

        unordered_set<int> unique;
        for (auto itr = freq.begin(); itr != freq.end(); itr++) {
            if (itr->second == 1) {
                unique.insert(itr->first);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (unique.contains(numsFreq[nums[i]])) {
                return nums[i];
            }
        }
        
        return -1;
    }
};