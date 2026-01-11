class Solution {
public:
    int residuePrefixes(string s) {
        int output = 0;

        unordered_set<char> us;
        for (int i = 0; i < s.length(); i++) {
            us.insert(s[i]);

            if ((i+1) % 3 == us.size()) {
                output++;
            }
        }

        return output;
    }
};