class Solution {
public:
    int getLucky(string s, int k) {
        
        string curr;

        for (char c : s)
        {
            string num = to_string(c - 'a' + 1);

            curr += num;
        }

        int output = 0;

        for (int i = 0; i < k; i++)
        {
            output = 0;

            for (char c : curr)
            {
                output += c - '0';
            }

            curr = to_string(output);
        }

        return output;
    }
};