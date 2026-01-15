class Solution {
public:
    bool scoreBalance(string s) {
        vector<int> prefix(s.length(), 0);
        int currSum = 0;

        for (int i = 0; i < s.length(); i++) {
            currSum += s[i] - 'a' + 1;
            prefix[i] = currSum;
        }

        for (int i = 0; i < s.length(); i++) {
            if (prefix[i] == (currSum - prefix[i])) {
                return true;
            }
        }

        return false;
    }
};