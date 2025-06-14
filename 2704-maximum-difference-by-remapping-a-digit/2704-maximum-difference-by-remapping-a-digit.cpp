class Solution {
public:
    int minMaxDifference(int num) {
        
        string checkMax = to_string(num);
        string checkMin = checkMax;

        int max = num;
        int min = num;

        for (int i = 0; i < checkMax.length(); i++)
        {
            if (checkMax[i] < '9')
            {
                char c = checkMax[i];
                for (int j = i; j < checkMax.length(); j++)
                {
                    if (checkMax[j] == c)
                    {
                        checkMax[j] = '9';
                    }
                }

                max = stoi(checkMax);
                break;
            }
        }

        char c = checkMin[0];
        for (int i = 0; i < checkMin.length(); i++)
        {
            if (checkMin[i] == c)
            {
                checkMin[i] = '0';
            }
        }

        min = stoi(checkMin);

        return max - min;
    }
};