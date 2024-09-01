class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        if (original.size() != m*n)
        {   
            return {};
        }

        vector<vector<int>> output;

        int index = 0;

        for (int i = 0; i < m; i++)
        {

            vector<int> curr;
            for (int j = 0; j < n; j++)
            {
                curr.push_back(original[index]);
                index++;
            }

            output.push_back(curr);
        }

        return output;  
    }
};