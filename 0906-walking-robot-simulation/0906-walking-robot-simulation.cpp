class Solution {
public:
    void changeDirection(char& direction, int change)
    {
        if (change == -1)
        {
            if (direction == 'N')
            {
                direction = 'E';
            }
            else if (direction == 'E')
            {
                direction = 'S';
            }
            else if (direction == 'S')
            {
                direction = 'W';
            }
            else
            {
                direction = 'N';
            }
        }
        else
        {
            if (direction == 'N')
            {
                direction = 'W';
            }
            else if (direction == 'W')
            {
                direction = 'S';
            }
            else if (direction == 'S')
            {
                direction = 'E';
            }
            else
            {
                direction = 'N';
            }
        }   
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        int x = 0;
        int y = 0;
        char direction = 'N';

        int output = 0;

        set<pair<int, int>> obs; // x and y obstacles

        for (int i = 0; i < obstacles.size(); i++)
        {
            obs.insert({obstacles[i][0], obstacles[i][1]});
        }

        for (int i = 0; i < commands.size(); i++)
        {
            if (commands[i] < 0)
            {
                changeDirection(direction, commands[i]);
            }
            else
            {
                if (direction == 'N' || direction == 'S')
                {
                    if (direction == 'N')
                    {
                        for (int j = 0; j < commands[i]; j++)
                        {
                            pair<int,int> curr;
                            curr.first = x;
                            curr.second = y+1;
                            if (obs.find(curr) != obs.end())
                            {
                                break;
                            }
                            else
                            {

                                y++;
                                if (x * x + y * y > output)
                                {
                                    output = x * x + y * y;
                                }
                            }
                        }
                    }
                    else
                    {
                        for (int j = 0; j < commands[i]; j++)
                        {
                            pair<int,int> curr;
                            curr.first = x;
                            curr.second = y-1;
                            if (obs.find(curr) != obs.end())
                            {
                                break;
                            }
                            else
                            {
                                y--;
                                if (x * x + y * y > output)
                                {
                                    output = x * x + y * y;
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (direction == 'W')
                    {
                        for (int j = 0; j < commands[i]; j++)
                        {
                            pair<int,int> curr;
                            curr.first = x-1;
                            curr.second = y;
                            if (obs.find(curr) != obs.end())
                            {
                                break;
                            }
                            else
                            {
                                x--;
                                if (x * x + y * y > output)
                                {
                                    output = x * x + y * y;
                                }
                            }
                        }
                    }
                    else
                    {
                        for (int j = 0; j < commands[i]; j++)
                        {
                            pair<int,int> curr;
                            curr.first = x+1;
                            curr.second = y;
                            if (obs.find(curr) != obs.end())
                            {
                                break;
                            }
                            else
                            {
                                x++;
                                if (x * x + y * y > output)
                                {
                                    output = x * x + y * y;
                                }
                            }
                        }
                    }
                }
            }

        }

        return output;
    }
};