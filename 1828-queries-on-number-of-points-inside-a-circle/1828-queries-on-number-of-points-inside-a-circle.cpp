class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        vector<int> answer;

        for (int i = 0; i < queries.size(); i++)
        {
            int counter = 0;
            for (int j = 0; j < points.size(); j++)
            {
                if (queries[i][2] >= sqrt( pow(points[j][0] - queries[i][0], 2)+ pow(points[j][1] - queries[i][1], 2)))
                {
                    counter++;
                }
            }
            answer.push_back(counter);
        }
        return answer;
    }
};