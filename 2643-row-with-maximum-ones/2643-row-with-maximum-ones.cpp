class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> output = {0,0};
        vector<int> empty;

        int counter = 0;
        int biggest = 0;

        for (int i = 0; i < mat.size(); i++)
        {
            counter = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    counter++;
                }
            }
            if (counter > biggest)
            {
                biggest = counter;
                output = empty;
                output.push_back(i);
                output.push_back(counter);
            }
        }
        return output;
    }
};