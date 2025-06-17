class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string output;
        int leftP = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                leftP++;
                if (leftP > 1) {
                    output.push_back(s[i]);
                }
            } else {
                leftP--;
                if (leftP > 0) {
                    output.push_back(s[i]);
                }
            }
        }

        return output;
    }
};