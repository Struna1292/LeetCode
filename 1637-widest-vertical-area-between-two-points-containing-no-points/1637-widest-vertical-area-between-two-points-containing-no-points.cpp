class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {

        sort(begin(points), end(points));

        int widest = 0;
        for (int i = 0; i < points.size()-1; i++)
        {
            if (points[i+1][0] - points[i][0] > widest)
            {
                widest = points[i+1][0] - points[i][0];
            }
        }

        return widest;
    }
};