class Solution {
public:
    vector<int> getLayerVector(int layer, vector<vector<int>>& grid) {
        vector<int> nums;

        for (int i = layer; i < grid[0].size() - layer - 1; i++) {
            nums.push_back(grid[layer][i]);
        }

        for (int i = layer; i < grid.size() - layer - 1; i++) {
            nums.push_back(grid[i][grid[0].size() - 1 - layer]);
        }

        for (int i = grid[0].size() - 1 - layer; i > layer; i--) {
            nums.push_back(grid[grid.size() - 1 - layer][i]);
        }

        for (int i = grid.size() - 1 - layer; i > layer; i--) {
            nums.push_back(grid[i][layer]);
        }

        return nums;
    }

    vector<int> rotateLeftVector(vector<int>& vec, int k) {
        k %= vec.size();

        vector<int> rotated = vec;

        for (int i = 0; i < vec.size(); i++) {
            rotated[i] = vec[(i+k) % vec.size()];
        }

        return rotated;
    }

    void setGridLayer(int layer, vector<int>& vec, vector<vector<int>>& grid) {
        int index = 0;

        for (int i = layer; i < grid[0].size() - layer - 1; i++) {
            grid[layer][i] = vec[index];
            index++;
        }

        for (int i = layer; i < grid.size() - layer - 1; i++) {
            grid[i][grid[0].size() - 1 - layer] = vec[index];
            index++;
        }

        for (int i = grid[0].size() - 1 - layer; i > layer; i--) {
            grid[grid.size() - 1 - layer][i] = vec[index];
            index++;
        }

        for (int i = grid.size() - 1 - layer; i > layer; i--) {
            grid[i][layer] = vec[index];
            index++;
        }
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int minSize = min(grid.size(), grid[0].size());
        int layers = minSize / 2;

        for (int i = 0; i < layers; i++) {
            vector<int> currLayer = getLayerVector(i, grid);
            vector<int> rotated = rotateLeftVector(currLayer, k);

            setGridLayer(i, rotated, grid);
        }

        return grid;
    }
};