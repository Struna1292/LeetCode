class Solution {
public:
    bool checkOnesSegment(string s) {
        
        bool onesSegment = false;
        char prev = '0';

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                if (prev != '1') {
                    if (onesSegment) {
                        return false;
                    }
                    else {
                        onesSegment = true;
                    }
                }
            }

            prev = s[i];
        }

        return onesSegment;
    }
};