class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        int shifts = k % mat[0].size();

        for (int i = 0; i < mat[0].size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {

                int index = i + shifts;

                if (index >= mat[0].size())
                {
                    index -= mat[0].size();
                }


                if (mat[j][i] != mat[j][index])
                {
                    return false;
                }
            }
        }

        return true;
    }
};