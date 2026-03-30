class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> even;
        unordered_map<char, int> odd;
        
        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                even[s1[i]]++;
            }
            else {
                odd[s1[i]]++;
            }
        }

        for (int i = 0; i < s1.length(); i++) {
            char c = s2[i];

            if (i % 2 == 0) {
                if (even[c] > 0) {
                    even[c]--;
                }
                else {
                    return false;
                }
            }
            else {
                if (odd[c] > 0) {
                    odd[c]--;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};