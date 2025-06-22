class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {

        vector<string> output;
        string curr = "";

        for (int i = 0; i < s.length(); i++) {
            curr.push_back(s[i]);
            if ((i+1) % k == 0) {
                output.push_back(curr);
                curr = "";
            }
        }

        if (curr.length() > 0) {
            while (curr.length() < k) {
                curr.push_back(fill);
            }
            output.push_back(curr);
        }

        return output;
    }
};