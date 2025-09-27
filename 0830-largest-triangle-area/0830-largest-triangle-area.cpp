class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        
        double output = 0;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                for (int k = j+1; k < points.size(); k++) {
                    double a = points[i][0] * (points[j][1] - points[k][1]);
                    double b = points[j][0] * (points[k][1] - points[i][1]);
                    double c = points[k][0] * (points[i][1] - points[j][1]);

                    double currArea = abs(a + b + c) / 2.0;

                    if (currArea > output) {
                        output = currArea;
                    }
                }
            }
        }

        return output;
    }
};