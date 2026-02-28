class Solution {
public:
    bool isDigitorialPermutation(int n) {
        
        vector<int> factorials = {
            1,
            1,
            2,
            6,
            24,
            120,
            720,
            5040,
            40320,
            362880
        };

        string s = to_string(n);
        vector<int> freq(10, 0);
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]-'0']++;
            sum += factorials[s[i]-'0'];
        }

        string result = to_string(sum);
        vector<int> resultFreq(10, 0);
        for (int i = 0; i < result.length(); i++) {
            resultFreq[result[i]-'0']++;
        }

        for (int i = 0; i < 10; i++) {
            if (resultFreq[i] != freq[i]) {
                return false;
            }
        }

        return true;
    }
};