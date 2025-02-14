class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;

        for (int n : arr1)
        {
            mp[n]++;    
        }
        
        vector<int> output;

        for (int n : arr2)
        {
            while (mp[n] > 0)
            {
                output.push_back(n);
                mp[n]--;
            }
        }

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            while (itr->second > 0)
            {
                output.push_back(itr->first);
                itr->second--;
            }
        }

        return output;
    }
};