class Solution {
public:
    string getEncryptedString(string s, int k) {
        
        string output = s;

        for (int i = 0; i < s.length(); i++)
        {
            output[i] = s[(i+k) % s.length()];
        }

        return output;
    }
};