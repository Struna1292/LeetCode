class Solution {
public:
    string clearDigits(string s) {
        
        string output;

        int counter = 0;

        for (int i = s.length()-1; i >= 0; i--)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                counter++;
            }
            else if (counter > 0)
            {
                counter--;
            }
            else
            {
                output.push_back(s[i]);
            }
        }

        int i = 0;
        int j = output.length()-1;

        while (i < j)
        {
            swap(output[i], output[j]);
            i++;
            j--;
        }

        return output;
    }
};