class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {

        for (int i = 0; i < coordinates.size() - 2; i++)
        {
            int a = (coordinates[i+2][1] -coordinates[i][1]) * (coordinates[i+1][0] - coordinates[i][0]);
            int b = (coordinates[i+1][1] - coordinates[i][1]) * (coordinates[i+2][0] -coordinates[i][0]);
            if (a != b)
            {
                return false;
            }
        }

        return true;
    }
};