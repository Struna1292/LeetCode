class Solution {
public:
    void helper(int i, int j, vector<vector<int>>& grid, int& prevHeight, queue<pair<int, int>>& que) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] != -1) {
            return;
        }

        grid[i][j] = prevHeight+1;
        que.push({i, j});
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        queue<pair<int, int>> que;

        // transform grid water to 0 height and land to not assigned = -1
        for (int i = 0; i < isWater.size(); i++) {
            for (int j = 0; j < isWater[i].size(); j++) {
                if (isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    que.push({i, j});
                }
                else {
                    isWater[i][j] = -1;
                }
            }
        }
        
        while (!que.empty()) {
            pair<int, int> curr = que.front();
            que.pop();
            
            int i = curr.first;
            int j = curr.second;
            int currHeight = isWater[i][j];

            helper(i+1, j, isWater, currHeight, que);
            helper(i-1, j, isWater, currHeight, que);
            helper(i, j+1, isWater, currHeight, que);
            helper(i, j-1, isWater, currHeight, que);
        }

        return isWater;
    }
};