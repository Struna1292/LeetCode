class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        map<int,int> ballColor;
        map<int,int> colorCount;

        vector<int> output;

        for (int i = 0; i < queries.size(); i++)
        {
            if (ballColor[queries[i][0]] != 0)
            {
                colorCount[ballColor[queries[i][0]]]--;
                if (colorCount[ballColor[queries[i][0]]] == 0)
                {
                    colorCount.erase(ballColor[queries[i][0]]);
                }
            }
            ballColor[queries[i][0]] = queries[i][1];
            colorCount[queries[i][1]]++;

            output.push_back(colorCount.size());
        }

        return output;
    }
};