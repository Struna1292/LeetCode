class Solution {
public:
    int DFS(int i, int j, vector<vector<int>>& triangle, vector<vector<bool>>& seen) {
        if (i == triangle.size()) {
            return 0;
        }
        else if (seen[i][j]) {
            return triangle[i][j];
        }

        int left = DFS(i+1, j, triangle, seen) + triangle[i][j];
        int right = DFS(i+1, j+1, triangle, seen) + triangle[i][j];

        seen[i][j] = true;
        triangle[i][j] = min(left, right);

        return triangle[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<bool>> seen;
        vector<bool> currRow;
        for (int i = 0; i < triangle.size(); i++) {
            currRow.push_back(false);
            seen.push_back(currRow);
        }

        int output = DFS(0, 0, triangle, seen);

        return output;
    }
};