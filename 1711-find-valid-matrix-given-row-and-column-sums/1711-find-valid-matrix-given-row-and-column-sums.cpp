class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        vector<vector<int>> output(rowSum.size(), vector<int>(colSum.size(), 0));

        for (int counter = 0; counter < (rowSum.size() * colSum.size()); counter++)
        {
            int lowest = 0;

            bool row = false;
            int index = -1;

            for (int i = 0; i < rowSum.size(); i++)
            {
                if (rowSum[i] != 0 && rowSum[i] < lowest || lowest == 0)
                {
                    lowest = rowSum[i];
                    row = true;
                    index = i;
                }
            }

            for (int i = 0; i < colSum.size(); i++)
            {
                if (colSum[i] != 0 && colSum[i] < lowest || lowest == 0)
                {
                    lowest = colSum[i];
                    row = false;
                    index = i;
                }
            }


            if (row)
            {
                int j = 0;
                while (colSum[j] < lowest)
                {
                    j++;
                }

                output[index][j] += lowest;

                rowSum[index] -= lowest;
                colSum[j] -= lowest;
            }
            else
            {
                int j = 0;
                while (rowSum[j] < lowest)
                {
                    j++;
                }

                output[j][index] += lowest;

                colSum[index] -= lowest;
                rowSum[j] -= lowest;
            }


        }

        return output;
    }
};