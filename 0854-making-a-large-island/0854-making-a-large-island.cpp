class Solution {
public:
    int islandSize(int i, int j, vector<vector<int>>& grid, int& mark) {
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[i].size() || 
            grid[i][j] == mark || grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = mark;
        int size = 1;

        size += islandSize(i-1, j, grid, mark);
        size += islandSize(i+1, j, grid, mark);
        size += islandSize(i, j-1, grid, mark);
        size += islandSize(i, j+1, grid, mark);

        return size;
    }

    int sizeAfterSwap(int i, int j, vector<vector<int>>& grid, vector<int>& mp) {
        unordered_set<int> islands;

        int curr = 1;

        if (i > 0 && grid[i-1][j] != 0) {
            islands.insert(grid[i-1][j]);
        }
        if (j > 0 && grid[i][j-1] != 0) {
            islands.insert(grid[i][j-1]);
        }
        if (i+1 < grid.size() && grid[i+1][j] != 0) {
            islands.insert(grid[i+1][j]);
        }
        if (j+1 < grid[i].size() && grid[i][j+1] != 0) {
            islands.insert(grid[i][j+1]);
        }

        for (int mark : islands) {
            curr += mp[mark];
        }

        return curr;
    }

    int largestIsland(vector<vector<int>>& grid) {
        // iterate through and count island size with DFS 
        // then assign number to this size to easily distinguish between the same size islands
        // while DFS mark grid[i][j] with picked number
        // iterate again but this time look only at empty space (0)
        // check all 4 directions and lookup which islands we can connect

        vector<int> mp(((grid.size()*grid.size())/2)+3); // maximum possible amount of islands is (grid.size()*grid.size())/2
        int currMark = 2;
        int largestIsland = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    int size = islandSize(i, j, grid, currMark);
                    mp[currMark] = size;
                    currMark++;

                    if (size > largestIsland) {
                        largestIsland = size;
                    }
                } else if (grid[i][j] == 0) {
                    if (i+1 < grid.size() && grid[i+1][j] == 1) { // check if there is island down
                        int size = islandSize(i+1, j, grid, currMark);
                        mp[currMark] = size;
                        currMark++;
                    }
                    if (j+1 < grid[i].size() && grid[i][j+1] == 1) { // check if there is island right
                        int size = islandSize(i, j+1, grid, currMark);
                        mp[currMark] = size;
                        currMark++;
                    }


                    int currLargest = sizeAfterSwap(i, j, grid, mp);
                    if (currLargest > largestIsland) {
                        largestIsland = currLargest;
                    }
                }
            }
        }

        return largestIsland;
    }
};