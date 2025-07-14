class Solution {
public:
    struct comparator {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[2] > b[2];
        }
    };

    bool isPositionValid(int i, int j, int rows, int cols) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            return false;
        }

        return true;
    }

    int minCost(vector<vector<int>>& grid) {
        
        // notice that at every node we have 4 edges to every direction but the one in grid[i][j] costs 0 and others 1

        vector<vector<int>> edges = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        }; // this order is required to future assign (i+1) to proper direction

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dists(rows, vector<int>(cols, INT_MAX));
        dists[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, comparator> pq; // min heap
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            int currI = pq.top()[0];
            int currJ = pq.top()[1];
            int currDist = pq.top()[2];
            pq.pop();

            if (currI+1 == rows && currJ+1 == cols) {
                return dists[rows-1][cols-1];
            }

            if (currDist > dists[currI][currJ]) {
                continue;
            }

            for (int i = 0; i < edges.size(); i++) {
                int nextI = currI + edges[i][0];
                int nextJ = currJ + edges[i][1];

                if (!isPositionValid(nextI, nextJ, rows, cols)) {
                    continue;
                }

                int dist = (grid[currI][currJ] == (i+1)) ? 0 : 1; // check for the arrow

                if (dist + currDist < dists[nextI][nextJ]) {
                    dists[nextI][nextJ] = dist + currDist;
                    pq.push({nextI, nextJ, dists[nextI][nextJ]});
                }
            }
        }

        return dists[rows-1][cols-1];
    }
};