class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> output;
        for (int i = 0; i < s.length(); i++)
        {
            int counter = 0;
            vector<int> curr = startPos;
            for (int j = i; j < s.length(); j++)
            {
                if (s[j] == 'R')
                {
                    if (curr[1]+1 == n)
                    {
                        break;
                    }
                    else
                    {
                        curr[1]++;
                    }
                }
                else if (s[j] == 'L')
                {
                    if (curr[1]-1 < 0)
                    {
                        break;
                    }
                    else
                    {
                        curr[1]--;
                    }
                }
                else if (s[j] == 'U')
                {
                    if (curr[0]-1 < 0)
                    {
                        break;
                    }
                    else
                    {
                        curr[0]--;
                    }
                }
                else
                {
                    if (curr[0]+1 == n)
                    {
                        break;
                    }
                    else
                    {
                        curr[0]++;
                    }
                }
                counter++;
            }
            output.push_back(counter);
        }
        return output;
    }
};