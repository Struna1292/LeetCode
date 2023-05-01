class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> output;

        class Used {
            public:
                int x,y;
        };

        vector<Used> indexes;

        int counter = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (A[i] == B[j])
                {
                    int counter1 = 0;
                    for (int k = 0; k < indexes.size(); k++)
                    {
                        if (indexes[k].x == i && indexes[k].y == j)
                        {
                            break;
                        }
                        else
                        {
                            counter1++;
                        }
                    }
                    if (counter1 == indexes.size())
                    {
                        counter++;
                        indexes.push_back({i,j});
                    }
                }
                if (B[i] == A[j])
                {
                    int counter1 = 0;
                    for (int k = 0; k < indexes.size(); k++)
                    {
                        if (indexes[k].x == j && indexes[k].y == i)
                        {
                            break;
                        }
                        else
                        {
                            counter1++;
                        }
                    }
                    if (counter1 == indexes.size())
                    {
                        counter++;
                        indexes.push_back({i,j});
                    }
                }
            }
            output.push_back(counter);
        }
        return output;
    }
};