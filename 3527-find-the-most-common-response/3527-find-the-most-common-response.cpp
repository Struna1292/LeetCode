class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> um;

        for (int i = 0; i < responses.size(); i++) {
            unordered_set<string> us;

            for (int j = 0; j < responses[i].size(); j++) {
                if (!us.contains(responses[i][j])) {
                    um[responses[i][j]]++;
                    us.insert(responses[i][j]);
                }
            }
        }

        string output;
        for (auto itr = um.begin(); itr != um.end(); itr++) {
            if (output.length() == 0 || itr->second > um[output] || (itr->second == um[output] && itr->first < output)) {
                output = itr->first;
            }
        }

        return output;
    }
};