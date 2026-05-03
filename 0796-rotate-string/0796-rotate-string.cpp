class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            
            for (int j = 0; j < s.length(); j++) {
                if (s[j] != goal[(j+i) % goal.length()]) {
                    break;
                }

                if (j+1 == s.length()) {
                    return true;
                }
            }
        }

        return false;
    }
};