class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // pair represents first and last index
        unordered_map<char, pair<int, int>> indexes;

        for (int i = 0; i < s.length(); i++) {
            if (!indexes.contains(s[i])) {
                indexes[s[i]] = { i, -1 };
            }
            else {
                indexes[s[i]].second = i;
            }
        }

        unordered_map<char, int> um;
        unordered_map<char, unordered_map<char, int>> prev;
        int output = 0;
        
        for (int i = 0; i < s.length(); i++) {
            
            if (indexes[s[i]].first == i) {
                prev[s[i]] = um;
            }
            else if (indexes[s[i]].second == i) {

                for (auto itr = um.begin(); itr != um.end(); itr++) {
                    char curr = itr->first;
                    int occs = itr->second;

                    if ((curr == s[i] && occs - prev[s[i]][curr] > 1) || (curr != s[i] && occs - prev[s[i]][curr] > 0)) {
                        output++;
                    }
                }

            }

            um[s[i]]++;
        }

        return output;
    }
};