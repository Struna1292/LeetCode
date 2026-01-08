class Solution {
public:
    string largestEven(string s) {
        string output;
        bool even = false;
        for (int i = s.length()-1; i >= 0; i--) {
            if (even) {
                output.push_back(s[i]);
            }
            else {
                if (s[i] == '2') {
                    even = true;
                    output.push_back(s[i]);
                }
            }
        }

        int i = 0;
        int j = output.length()-1;
        while (i < j) {
            swap(output[i], output[j]);
            i++;
            j--;
        }

        return output;
    }
};