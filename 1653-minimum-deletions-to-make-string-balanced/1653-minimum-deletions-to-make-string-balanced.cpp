class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> prefix(s.length()+1, 0);
        int counter = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'b') {
                counter++;
            }
            prefix[i+1] = counter;
        }
        
        vector<int> suffix(s.length()+1, 0);
        counter = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] == 'a') {
                counter++;
            }

            suffix[i] = counter;
        }

        int output = s.length();
        for (int i = 0; i < prefix.size(); i++) {
            if (output > prefix[i] + suffix[i]) {
                output = prefix[i] + suffix[i];
            }
        }

        return output;
    }
};