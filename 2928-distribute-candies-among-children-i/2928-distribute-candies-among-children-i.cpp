class Solution {
public:

    int distributeCandies(int n, int limit) {
        set<vector<int>> combinations;

        for (int i = 0; i <= limit; i++)
        {
            int currN = n-i;
            if (currN < limit)
            {
                for (int j = 0; j <= currN; j++)
                {
                    int currN2 = n - j - i;
                    if (currN2 <= limit)
                    {
                        combinations.insert({i,j,currN2});
                    }
                }
            }
            else
            {
                for (int j = 0; j <= limit; j++)
                {
                    int currN2 = n - j - i;
                    if (currN2 <= limit)
                    {
                        combinations.insert({i,j,currN2});
                    }
                }
            }
        }

        return combinations.size();
    }
};