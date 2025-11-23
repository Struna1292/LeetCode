class Solution {
public:
    long long sumAndMultiply(int n) {
        
        int sum = 0;
        string stringX = "";

        string curr = to_string(n);
        for (int i = 0; i < curr.length(); i++) {
            if (curr[i] != '0') {
                sum += curr[i] - '0';
                stringX.push_back(curr[i]);
            }
        }

        int x = 0;
        if (stringX.length() > 0) {
            x = stoi(stringX);
        }

        return (long long)(x) * (long long)(sum);
    }
};