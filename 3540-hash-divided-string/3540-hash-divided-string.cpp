class Solution {
public:
    string stringHash(string s, int k) {
        
        string output;

        for (int i = 0; i < s.length(); i+=k)
        {
            int curr = 0;
            for (int j = i; j < i+k; j++)
            {
                curr += s[j] - 'a';
            }

            output.push_back((curr % 26) + 'a');
        }

        return output;
    }
};