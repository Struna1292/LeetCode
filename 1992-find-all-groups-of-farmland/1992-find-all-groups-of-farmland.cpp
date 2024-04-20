class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>> output;

        for (int i = 0; i < land.size(); i++)
        {
            for (int j = 0; j < land[i].size(); j++)
            {
                // starting corner
                if (land[i][j] == 1 && (i == 0 || land[i-1][j] == 0) && (j == 0 || land[i][j-1] == 0))
                {
                    int k = j;
                    while (k+1 < land[i].size() && land[i][k+1] == 1)
                    {
                        k++;
                    }

                    int l = i;

                    while (l+1 < land.size() && land[l+1][j] == 1)
                    {
                        l++;
                    }

                    output.push_back({i,j,l,k});
                }
            }
        }


        return output;
    }
};