class Spreadsheet {
public:

    vector<vector<int>> grid;

    Spreadsheet(int rows) {
        grid = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    int getColumn(string& cell) {
        return cell[0] - 'A';
    }

    int getRow(string& cell) {
        string curr;
        for (int i = 1; i < cell.length(); i++) {
            curr.push_back(cell[i]);
        }

        return stoi(curr)-1;
    }

    void setCell(string cell, int value) {
        int column = getColumn(cell);
        int row = getRow(cell);
        grid[row][column] = value;
    }
    
    void resetCell(string cell) {
        int column = getColumn(cell);
        int row = getRow(cell);
        grid[row][column] = 0;
    }
    
    int getValue(string formula) {

        int currSum = 0;
        string curr;
        for (int i = 1; i < formula.length(); i++) {
            if (formula[i] == '+') {

                if (curr[0] >= '0' && curr[0] <= '9') {
                    currSum = stoi(curr);
                }
                else {
                    int column = getColumn(curr);
                    int row = getRow(curr);
                    currSum = grid[row][column];
                }

                curr = "";
            }
            else {
                curr.push_back(formula[i]);
            }
        }

        if (curr[0] >= '0' && curr[0] <= '9') {
            currSum += stoi(curr);
        }
        else {
            int column = getColumn(curr);
            int row = getRow(curr);
            currSum += grid[row][column];
        }


        return currSum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */