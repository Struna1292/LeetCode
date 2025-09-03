class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int digits[10] = { 0 };

        string s = to_string(n);

        for (int i = 0; i < s.length(); i++) {
            digits[s[i]-'0']++;
        }

        int leastFrequent = -1;

        for (int i = 0; i < 10; i++) {
            if (digits[i] > 0 && (leastFrequent == -1 || digits[i] < digits[leastFrequent])) {
                leastFrequent = i;
            }
        }

        return leastFrequent;
    }
};