class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        vector<int> zeros;

        for (int i = 0; i < grid.size(); i++) {

            int zerosCounter = 0;
            for (int j = grid[i].size()-1; j >= 1; j--) {
                
                if (grid[i][j] == 0) {
                    zerosCounter++;
                }
                else {
                    break;
                }   
            }

            zeros.push_back(zerosCounter);
        }

        int swapsCount = 0;
        int n = grid.size()-1;
        for (int i = 0; i < zeros.size(); i++) {
            int j = i;
            while (j < zeros.size() && zeros[j] < n - i) {
                j++;
            }

            if (j == zeros.size()) {
                return -1;
            }

            while (j != i) {
                swap(zeros[j-1], zeros[j]);
                swapsCount++;
                j--;
            }
        }

        return swapsCount;
    }
};