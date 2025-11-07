class Solution {
public:
    long long removeZeros(long long n) {
        string output;
        string s = to_string(n);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '0') {
                output.push_back(s[i]);
            }
        }

        return stoll(output);
    }
};