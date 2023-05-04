class Solution {
public:
    string predictPartyVictory(string senate) {

        int radiant = 0;
        int dire = 0;

        string curr = senate;
        while (curr.length() > 1 && radiant == 0 && dire == 0)
        {
            radiant = 0;
            dire = 0;
            for (int i = 0; i < curr.length(); i++)
            {
                if (curr[i] == 'R')
                {
                    if (dire > 0)
                    {
                        dire--;
                        curr.erase(i, 1);
                        i--;
                    }
                    else
                    {
                        radiant++;
                    }
                }
                else
                {
                    if (radiant > 0)
                    {
                        radiant--;
                        curr.erase(i, 1);
                        i--;
                    }
                    else
                    {
                        dire++;
                    }
                }
            }

            if (dire > 0)
            {
                for (int i = 0; i < curr.length(); i++)
                {
                    if (curr[i] == 'R' && dire > 0)
                    {
                        curr.erase(i, 1);
                        i--;
                        dire--;
                    }
                }
            }
            else if (radiant > 0)
            {
                for (int i = 0; i < curr.length(); i++)
                {
                    if (curr[i] == 'D' && radiant > 0)
                    {
                        curr.erase(i, 1);
                        i--;
                        radiant--;
                    }
                }
            }
        }

        if (curr[0] == 'R')
        {
            return "Radiant";
        }
        else
        {
            return "Dire";
        }
    }
};