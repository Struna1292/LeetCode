class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;

        int j = 0;

        int counter = 0;
        int range = 0;
        int size = matrix.size() * matrix[0].size();
        while (counter < size)
        {
            j = range;
            for (int i = range; i < matrix[0].size()-range; i++) // right traversal
            {
                output.push_back(matrix[j][i]);
                counter++;
            }

            j = matrix[0].size()-1-range;
            for (int i = range+1; i < matrix.size()-range; i++) // down traversal
            {
                output.push_back(matrix[i][j]);
                counter++;
            }

            j = matrix.size()-1-range;
            for (int i = matrix[0].size()-2-range; i >= range; i--) // left traversal
            {
                output.push_back(matrix[j][i]);
                counter++;
            }

            j = range;
            for (int i = matrix.size()-2-range; i >= range+1; i--) // up traversal
            {
                output.push_back(matrix[i][j]);
                counter++;
            }
            range++;
        }

        vector<int> correct;

        for (int i = 0; i < size; i++)
        {
            correct.push_back(output[i]);
        }
        return correct;
    }
};