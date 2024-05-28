class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        vector<int> diff(s.length(), 0);

        for (int i = 0; i < s.length(); i++)
        {
            diff[i] = abs(s[i] - t[i]);
            cout << diff[i] << " ";
        }

        int i = 0;
        int j = 0;
        int currSum = 0;

        int currLength = 0;

        int output = 0;

        while (j < s.length())
        {
            if (diff[j] + currSum <= maxCost)
            {
                currLength++;
                currSum += diff[j];

                j++;
            }
            else
            {
                if (currLength > output)
                {
                    output = currLength;
                }

                currSum -= diff[i];
                i++;
                currLength--;
            }
        }


        if (currLength > output)
        {
            output = currLength;
        }


        return output;
    }
};