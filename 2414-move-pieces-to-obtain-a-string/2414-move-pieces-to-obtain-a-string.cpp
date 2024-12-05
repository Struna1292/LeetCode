class Solution {
public:
    bool canChange(string start, string target) {

        for (int i = 0; i < target.length(); i++)
        {
            if (target[i] != start[i])
            {
                if (target[i] == 'L')
                {
                    if (start[i] == 'R')
                    {
                        return false;
                    }
                    else if (start[i] == '_')
                    {
                        int j = i+1;
                        while (j < start.length())
                        {
                            if (start[j] == 'R')
                            {
                                return false;
                            }
                            else if (start[j] == 'L')
                            {
                                swap(start[i], start[j]);
                                break;
                            }
                            j++;
                        }
                    }
                }
                else if (target[i] == 'R')
                {
                    return false;
                }
                else // '_'
                {
                    if (start[i] == 'L')
                    {
                        return false;
                    }
                    else if (start[i] == 'R')
                    {
                        int j = i+1;
                        while (j < start.length())
                        {
                            if (start[j] == 'L')
                            {
                                return false;
                            }
                            else if (start[j] == '_')
                            {
                                swap(start[i], start[j]);
                                break;
                            }
                            j++;
                        }
                    }
                }

                if (target[i] != start[i])
                {
                    return false;
                }

            }
        }

        return true;
    }
};