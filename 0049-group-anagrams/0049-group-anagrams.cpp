class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string curr = strs[i];
            sort(begin(curr), end(curr));
            mp[curr].push_back(strs[i]);
        }

        vector<vector<string>> output;

        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            output.push_back(itr->second);
        }

        return output;
    }
};