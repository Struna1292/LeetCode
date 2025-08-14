class Solution {
public:
    string largestGoodInteger(string num) {
        
        char prev = 0;

        for (int i = 1; i < num.length()-1; i++) {
            if (num[i] > prev && num[i-1] == num[i] && num[i-1] == num[i+1]) {
                prev = num[i];
            }
        }

        if (prev == 0) {
            return "";
        }

        string output;
        for (int i = 0; i < 3; i++) {
            output.push_back(prev);
        }

        return output;
    }
};