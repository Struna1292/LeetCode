class Solution {
public:

    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        map<int,int>::iterator itr;

        vector<pair<int,int>> freq;

        for (itr = mp.begin(); itr != mp.end(); itr++)
        {
            freq.push_back({itr->second, itr->first});
        }

        sort(freq.begin(), freq.end(), [](const auto& a,const auto& b){
            return std::tie(a.first,b.second) < std::tie(b.first,a.second);
            });

        vector<int> output;

        for (int i = 0; i < freq.size(); i++)
        {
            for (int j = 0; j < freq[i].first; j++)
            {
                output.push_back(freq[i].second);
            }
        }

        return output;
    }
};