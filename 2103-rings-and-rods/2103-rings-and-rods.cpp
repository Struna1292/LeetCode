class Solution {
public:
    int countPoints(string rings) {
        class Rods
        {
            public:
                char num;
                int r,g,b;
        };

        vector<Rods> rods;
        char prev = rings[0];
        for (int i = 1; i < rings.length(); i++)
        {
            if (rings[i] >= '0' && rings[i] <= '9')
            {
                int counter = 0;
                for (int j = 0; j < rods.size(); j++)
                {
                    if (rods[j].num == rings[i])
                    {
                        if (prev == 'R')
                        {
                            rods[j].r++;
                        }
                        else if (prev == 'G')
                        {
                            rods[j].g++;
                        }
                        else if (prev == 'B')
                        {
                            rods[j].b++;
                        }
                        break;
                    }
                    else
                    {
                        counter++;
                    }
                }
                if (counter == rods.size())
                {
                    rods.push_back({rings[i], 0, 0, 0});
                    i--;
                }
            }
            else
            {
                prev = rings[i];
            }
        }

        int counter = 0;
        for (int i = 0; i < rods.size(); i++)
        {
            if (rods[i].r > 0 && rods[i].g > 0 && rods[i].b > 0)
            {
                counter++;
            }
        }
        return counter;
    }
};