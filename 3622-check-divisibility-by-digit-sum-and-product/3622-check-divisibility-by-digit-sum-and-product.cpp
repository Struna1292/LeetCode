class Solution {
public:
    bool checkDivisibility(int n) {
        string s = to_string(n);
        int product = s[0] - '0';
        int sum = product;

        for (int i = 1; i < s.length(); i++) {
            product *= (s[i] - '0');
            sum += (s[i] - '0');
        }

        return n % (product + sum) == 0;
    }
};