class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        
        long long output = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
            {
                int index = t[i] - 'a';

                long long next = 0;

                int j = s[i] - 'a';
                while (true)
                {
                    
                    if (j % 26 == index)
                    {
                        break;
                    }
                    next += nextCost[j % 26];
                    j++;
                }

                long long prev = 0;

                j = s[i] - 'a';
                while (true)
                {
                    if (j == -1)
                    {
                        j = 25;
                    }
                    if (j == index)
                    {
                        break;
                    }
                    prev += previousCost[j];
                    j--;
                }

                if (prev > next)
                {
                    cout << next << endl;
                    output += next;
                }
                else
                {
                    cout << prev << endl;
                    output += prev;
                }
            }

        }

        return output;
    }
};