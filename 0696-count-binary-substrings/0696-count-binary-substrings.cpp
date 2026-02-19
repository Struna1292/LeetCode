class Solution {
public:
    int countBinarySubstrings(string s) {
        int output = 0;

        int currCounter = 0;
        int prevCounter = 0;
        char prev = s[0];
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == prev) {
                currCounter++;
            }
            else {
                output += min(prevCounter, currCounter);
                
                prevCounter = currCounter;
                prev = s[i];
                currCounter = 1;
            }
        }
        output += min(prevCounter, currCounter);

        return output;
    }
};