class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        sort(begin(banned), end(banned));

        int counter = 0;
        int j = 0;
        int currSum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i != banned[j])
            {
                if (i > banned[j] && j+1 != banned.size())
                {
                    i--;
                    j++;
                }
                else
                {
                    currSum += i;
                    if (currSum > maxSum)
                    {
                        break;
                    }
                    else
                    {
                        counter++;
                    }
                }
            }
            else
            {
                j++;
            }

            if (j >= banned.size())
            {
                j = banned.size()-1;
            }
        }

        return counter;
    }
};