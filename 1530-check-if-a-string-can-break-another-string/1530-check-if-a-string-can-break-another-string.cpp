class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(begin(s1), end(s1));
        sort(begin(s2), end(s2));

        bool s1Breaks = true;
        bool s2Breaks = true;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] > s2[i]) {
                s2Breaks = false;
            }
            else if (s1[i] < s2[i]) {
                s1Breaks = false;
            }

            if (!s1Breaks && !s2Breaks) {
                break;
            }

            if (i+1 == s1.length()) {
                return true;
            }
        }

        return false;
    }
};