class Solution {
public:
    struct Comparator {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] > b[0];
        }
    };

    int swimInWater(vector<vector<int>>& grid) {

        vector<vector<int>> directions = {
            {-1, 0}, // up
            {0, 1}, // right
            {1, 0}, // down
            {0, -1}
        };

        vector<vector<int>> costs(grid.size(), vector<int>(grid[0].size(), INT_MAX));

        // [0] = cost, [1] = i, [2] = j
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;
        pq.push({grid[0][0], 0, 0});
        costs[0][0] = grid[0][0];

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int currCost = curr[0];
            int currI = curr[1];
            int currJ = curr[2];

            if (costs[currI][currJ] < currCost) {
                continue;
            }

            if (currI == grid.size() && currJ == grid.size()) {
                break;
            }

            for (int i = 0; i < directions.size(); i++) {
                int nextI = currI + directions[i][0];
                int nextJ = currJ + directions[i][1];

                if (nextI < 0 || nextJ < 0 || nextI == grid.size() || nextJ == grid[nextI].size()) {
                    continue;
                }

                int nextCost = max(grid[nextI][nextJ], currCost);

                if (nextCost < costs[nextI][nextJ]) {
                    pq.push({nextCost, nextI, nextJ});
                    costs[nextI][nextJ] = nextCost;
                }
            }
        }

        return costs[grid.size()-1][grid.size()-1];
    }
};