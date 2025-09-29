class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        
        string s = to_string(n);
        vector<int> output;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                continue;
            }

            string curr(s.length()-i, '0');
            curr[0] = s[i];
            output.push_back(stoi(curr));
        }

        return output;
    }
};