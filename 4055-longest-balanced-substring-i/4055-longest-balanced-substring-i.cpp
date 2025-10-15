class Solution {
public:
    bool sameOccurrences(vector<int>& curr) {
        int prev = 0;
        for (int i = 0; i < curr.size(); i++) {
            if (prev == 0) {
                prev = curr[i];
            }
            else if (curr[i] == 0) {
                continue;
            }
            else if (prev != curr[i]) {
                return false;
            }   
        }
        return true;
    }

    int longestBalanced(string s) {
        if (s.length() == 1) {
            return 1;
        }

        int output = 0;

        for (int i = 0; i < s.length(); i++) {
            vector<int> curr(26, 0);
            for (int j = i; j < s.length(); j++) {
                curr[s[j]-'a']++;

                if (sameOccurrences(curr)) {
                    output = max(output, j-i+1);
                }
            }
        }

        return output;
    }
};