class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int minusMaximum = 2;
        int maximumCounter = 0;
        int positiveMinimum = -1;

        int negativeCounter = 0;

        bool isZero = false;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] < 0)
                {
                    negativeCounter++;
                    if (minusMaximum == 2 || matrix[i][j] > minusMaximum)
                    {
                        minusMaximum = matrix[i][j];
                        maximumCounter = 1;
                    }
                    else if (matrix[i][j] == minusMaximum)
                    {
                        maximumCounter++;
                    }
                }
                else if (matrix[i][j] == 0)
                {
                    isZero = true;
                }
                else 
                {
                    if (positiveMinimum == -1 || positiveMinimum > matrix[i][j])
                    {
                        positiveMinimum = matrix[i][j];
                    }
                }
            }
        }

        bool even = (negativeCounter % 2 == 0) || isZero || negativeCounter == 0;

        if (!even)
        {
            if ((minusMaximum * -1) > positiveMinimum && positiveMinimum != -1)
            {
                minusMaximum = 1;
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] < 0)
                {
                    if (even)
                    {
                        matrix[i][j] *= -1;
                    }
                    else
                    {
                        if (matrix[i][j] != minusMaximum)
                        {
                            matrix[i][j] *= -1;
                        }
                        else
                        {
                            if (maximumCounter > 1)
                            {
                                matrix[i][j] *= -1;
                                maximumCounter--;
                            }
                        }
                    }
                }
                else
                {
                    if (positiveMinimum == matrix[i][j] && minusMaximum == 1)
                    {
                        matrix[i][j] *= -1;
                        minusMaximum = 2;
                    }
                }
            }
        }

        long long output = 0;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                output += matrix[i][j];
            }
        }

        return output;
    }
};