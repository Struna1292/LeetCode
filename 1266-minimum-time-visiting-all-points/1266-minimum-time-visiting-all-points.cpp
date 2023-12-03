class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int output = 0;
        
        for (int i = 1; i < points.size(); i++)
        {
            int x = abs(points[i-1][0] - points[i][0]);
            int y = abs(points[i-1][1] - points[i][1]);

            if (x <= y)
            {
                output += y;
            }
            else
            {
                output += x;
            }
            
        }

        return output;
    }
};