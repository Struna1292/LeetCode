class Solution {
public:
    struct Point {
        int i;
        int j;
        Point(int i, int j) {
            this->i = i,
            this->j = j;
        }
    };

    bool isSize4(Point& start, Point& end) {
        if (start.i+1 == end.i && start.j+1 == end.j) {
            return true;
        }

        return false;
    }

    void fillSize4Square(int i, int j, vector<vector<int>>& grid, int& currNum) {
        grid[i][j+1] = currNum + 1;
        grid[i+1][j+1] = currNum + 2;
        grid[i+1][j] = currNum + 3;
        grid[i][j] = currNum + 4;
        currNum += 4;
    }

    void helper(Point start, Point end, vector<vector<int>>& grid, int& currNum) {
        if (isSize4(start, end)) {
            fillSize4Square(start.i, start.j, grid, currNum);
        }
        else {
            int halfI = (start.i + end.i) / 2;
            int halfJ = (start.j + end.j) / 2;

            Point topLeftStart = start;
            Point topLeftEnd = Point(halfI, halfJ);

            Point topRightStart = Point(start.i, halfJ + 1);
            Point topRightEnd = Point(halfI, end.j);

            Point botLeftStart = Point(halfI + 1, start.j);
            Point botLeftEnd = Point(end.i, halfJ);

            Point botRightStart = Point(halfI + 1, halfJ + 1);
            Point botRightEnd = end;

            helper(topRightStart, topRightEnd, grid, currNum);
            helper(botRightStart, botRightEnd, grid, currNum);
            helper(botLeftStart, botLeftEnd, grid, currNum);
            helper(topLeftStart, topLeftEnd, grid, currNum);
        }
    }

    vector<vector<int>> specialGrid(int n) {
        if (n == 0) {
            return {{0}};
        }

        int size = pow(2, n);
        int curr = -1;
        vector<vector<int>> grid(size, vector<int>(size, 0));
        helper(Point(0, 0), Point(size-1, size-1), grid, curr);

        return grid;
    }
};