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

        for (int length = s.length(); length >= 2; length--) {
            vector<int> curr(26, 0);
            for (int i = 0; i < length; i++) {
                curr[s[i]-'a']++;
            }

            if (sameOccurrences(curr)) {
                return length;
            }

            for (int i = length; i < s.length(); i++) {
                curr[s[i]-'a']++;
                curr[s[i-length]-'a']--;

                if (sameOccurrences(curr)) {
                    return length;
                }
            }
        }

        return 1;
    }
};