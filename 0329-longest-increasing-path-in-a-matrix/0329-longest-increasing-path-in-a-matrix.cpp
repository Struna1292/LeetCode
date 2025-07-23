class Solution {
public:
    int DFS(int i, int j, vector<vector<int>>& matrix,
            vector<vector<int>>& bestSizes, int prev) {

        if (i < 0 || i >= matrix.size() ||
            j < 0 || j >= matrix[i].size() ||
            (prev >= matrix[i][j])) {
            return 0;
        }

        if (bestSizes[i][j] != 0) { // if we already traveled this way we know the best path
            return bestSizes[i][j];
        }

        // find which way we can get the furthest
        int currBest = -1; 

        currBest = max(currBest, DFS(i, j-1, matrix, bestSizes, matrix[i][j])); // left
        currBest = max(currBest, DFS(i-1, j, matrix, bestSizes, matrix[i][j])); // right
        currBest = max(currBest, DFS(i, j+1, matrix, bestSizes, matrix[i][j])); // up
        currBest = max(currBest, DFS(i+1, j, matrix, bestSizes, matrix[i][j])); // down

        bestSizes[i][j] = currBest+1; // +1 because we need to increment current step

        return bestSizes[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // memorize best max size of current i j while iterating, so we dont need to reiterate same paths
        vector<vector<int>> bestSizes(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxSize = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                maxSize = max(maxSize, DFS(i, j, matrix, bestSizes,-1));
            }
        }

        return maxSize;
    }
};