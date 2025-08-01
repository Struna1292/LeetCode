class Solution {
public:
    struct comparator {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[2] > b[2];
        }
    };

    bool existInGrid(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) {
            return false;
        }
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if (grid[0][0] == 1) { // cant even start pathing
            return -1;
        }
        
        vector<vector<int>> directions = {
            {-1, 0}, // up
            {-1, 1},
            {0, 1}, // right
            {1, 1},
            {1, 0}, // down
            {1, -1},
            {0, -1}, // left
            {-1, -1}
        };

        // dijkstra
        vector<vector<int>> dists(grid.size(), vector<int>(grid[0].size(), INT_MAX));

        // pq vector<int> describes [0] = i, [1] = j, [2] = currCost
        priority_queue<vector<int>, vector<vector<int>>, comparator> pq; // min heap
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            int currI = curr[0];
            int currJ = curr[1];
            int currCost = curr[2];
            pq.pop();

            if (currI+1 == grid.size() && currJ+1 == grid[currI].size()) {
                return currCost+1;
            }

            if (currCost > dists[currI][currJ]) {
                continue;
            }

            for (int i = 0; i < directions.size(); i++) {
                int nextI = currI + directions[i][0];
                int nextJ = currJ + directions[i][1];

                if (!existInGrid(nextI, nextJ, grid) || grid[nextI][nextJ] == 1) {
                    continue;
                }

                int nextCost = currCost + 1;
                if (nextCost < dists[nextI][nextJ]) {
                    dists[nextI][nextJ] = nextCost;
                    pq.push({nextI, nextJ, nextCost});
                }
            }
        }

        return -1;
    }
};