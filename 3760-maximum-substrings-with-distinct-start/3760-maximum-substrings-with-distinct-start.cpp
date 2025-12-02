class Solution {
public:
    int maxDistinct(string s) {
        
        unordered_map<char, int> um;

        for (int i = 0; i < s.length(); i++) {
            um[s[i]]++;
        }

        return um.size();
    }
};