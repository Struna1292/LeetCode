class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>> output;

        for (int i = 0; i+k <= grid.size(); i++) {
            vector<int> currMins;

            for (int j = 0; j+k <= grid[i].size(); j++) {
                unordered_set<int> us;
                vector<int> distinct;

                for (int g = 0; g < k; g++) {
                    for (int h = 0; h < k; h++) {
                        if (!us.contains(grid[i+g][j+h])) {
                            us.insert(grid[i+g][j+h]);
                            distinct.push_back(grid[i+g][j+h]);
                        }
                    }
                }

                sort(begin(distinct), end(distinct));
                if (distinct.size() == 1) {
                    currMins.push_back(0);
                }
                else {
                    int currMin = INT_MAX;
                    for (int l = 1; l < distinct.size(); l++) {
                        currMin = min(currMin, distinct[l] - distinct[l-1]);
                    }
                    currMins.push_back(currMin);
                }
                
            }

            output.push_back(currMins);
        }

        return output;
    }
};