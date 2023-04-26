class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        class Point 
        {
            public:
                int x, y, index;
        };
        
        vector<Point> possible;
        for (int i = 0; i < points.size(); i++)
        {
            if (points[i][0] == x || points[i][1] == y)
            {
                possible.push_back({points[i][0], points[i][1], i});
            }
        }

        if (possible.size() > 0)
        {
            int smallIndex = 0;
            for (int i = 1; i < possible.size(); i++)
            {
                if (abs(possible[i].x - x) + abs(possible[i].y - y) < abs(possible[smallIndex].x - x) + abs(possible[smallIndex].y - y))
                {
                    smallIndex = i;
                }
            }
            return possible[smallIndex].index;
        }
        return -1;
    }
};