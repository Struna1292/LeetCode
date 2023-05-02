class Solution {
public:
    string freqAlphabets(string s) {
        string output;
        for (int i = s.length()-1; i >= 0; i--)
        {
            int num = 0;
            if (s[i] == '#')
            {
                num += s[i-2] - '0';
                num *= 10;
                num += s[i-1] - '0';
                output.push_back(num + 'a'-1);
                i -= 2;
            }
            else
            {
                output.push_back((s[i] - '0') + 'a'-1);
            }
        }

        int j = output.length()-1;
        for (int i = 0; i < output.length()/2; i++)
        {
            swap(output[i],output[j]);
            j--;
        }
        return output;
    }
};