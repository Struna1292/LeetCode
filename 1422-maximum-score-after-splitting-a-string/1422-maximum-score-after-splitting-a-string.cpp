class Solution {
public:
    int maxScore(string s) {

        int i = 0;
        int j = s.length()-1;

        vector<int> zeros(s.length()+1, 0);
        vector<int> ones(s.length()+1, 0);

        int zerosCount = 0;
        int onesCount = 0;

        while (i < s.length())
        {
            if (s[i] == '0')
            {
                zerosCount++;
            }

            if (s[j] == '1')
            {
                onesCount++;
            }

            zeros[i+1] = zerosCount;
            ones[j] = onesCount;

            i++;
            j--;
        }

        int output = 0;

        for (i = 1; i < zeros.size()-1; i++)
        {
            if (zeros[i] + ones[i] > output)
            {
                output = zeros[i] + ones[i];
            }
        }
        

        return output;
    }
};