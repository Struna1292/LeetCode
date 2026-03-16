class Solution {
public:
    bool fitsRhombus(int i, int j, int length, vector<vector<int>>& grid) {
        if (i+(length-1)*2 < grid.size() 
            && j+length-1 < grid[i].size() 
            && j-(length-1) >= 0) {
            return true;
        }
        return false;
    }

    int getRhombusSum(int i, int j, int size, vector<vector<int>>& grid) {
        size--;

        int sum = 0;
        for (int k = 0; k < size; k++) {
            sum += grid[i+k][j+k];

            sum += grid[i+size+k][j+size-k];

            sum += grid[i+size*2-k][j-k];

            sum += grid[i+size-k][j-size+k];
        }

        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> us;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (us.contains(grid[i][j])) {
                    continue;
                }
                us.insert(grid[i][j]);

                if (pq.size() < 3) {
                    pq.push(grid[i][j]);
                }
                else if (grid[i][j] > pq.top()) {
                    pq.pop();
                    pq.push(grid[i][j]);
                }
            }
        }

        for (int length = 2; (length-1)*2 <= grid.size() && (length-1)*2 <= grid[0].size(); length++) {

            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (fitsRhombus(i, j, length, grid)) {
                        int currSum = getRhombusSum(i, j, length, grid);

                        if (us.contains(currSum)) {
                            continue;
                        }
                        us.insert(currSum);

                        if (pq.size() < 3) {
                            pq.push(currSum);
                        }
                        else if (currSum > pq.top()) {
                            pq.pop();
                            pq.push(currSum);
                        }
                    }
                }
            }

        }

        vector<int> output;
        while (!pq.empty()) {
            output.push_back(pq.top());
            pq.pop();
        }

        int i = 0;
        int j = output.size()-1;
        while (i < j) {
            swap(output[i], output[j]);
        }

        return output;
    }
};