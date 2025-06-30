class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        map<int,int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        int output = 0;
        int prevNum = -1;
        int prevCount = -1;

        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            if ((itr->first - prevNum) == 1 && (itr->second + prevCount) > output) {
                output = itr->second + prevCount;
            }
            prevNum = itr->first;
            prevCount = itr->second;
        }

        return output;
    }
};