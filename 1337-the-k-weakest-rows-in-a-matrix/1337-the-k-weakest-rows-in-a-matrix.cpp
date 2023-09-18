class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> rows; // value and index

        for (int i = 0; i < mat.size(); i++)
        {
            int value = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    value++;
                }
            }
            rows.push_back({value,i});
        }

        sort(begin(rows), end(rows));

        vector<int> output;

        for (int i = 0; i < k; i++)
        {
            output.push_back(rows[i].second);
        }

        return output;
    }
};