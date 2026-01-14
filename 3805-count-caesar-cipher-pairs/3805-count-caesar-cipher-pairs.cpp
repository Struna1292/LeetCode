class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, int> um;

        for (int i = 0; i < words.size(); i++) {
            int offset = words[i][0] - 'a';
            for (int j = 0; j < words[i].length(); j++) {
                words[i][j] -= offset;
                if (words[i][j] < 'a') {
                    words[i][j] += 26;
                }
            }
            um[words[i]]++;
        }

        long long output = 0;
        for (auto itr = um.begin(); itr != um.end(); itr++) {
            for (int i = 1; i < itr->second; i++) {
                output += i;
            }
        }

        return output;
    }
};