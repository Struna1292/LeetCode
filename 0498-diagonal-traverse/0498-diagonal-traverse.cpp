class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<vector<int>> leftDiagonals;
        // diagonals starting from first column
        for (int i = 0; i < mat.size(); i+=2) {
            vector<int> curr;
            for (int j = 0; j < mat[i].size() && (i-j) >= 0; j++) {
                curr.push_back(mat[i-j][j]);
            }

            leftDiagonals.push_back(curr);
        }

        // diagonals starting from last row
        int index = 2; 
        if (mat.size() % 2 == 0) {
            index = 1;
        }
        for (int i = index; i < mat[mat.size()-1].size(); i+=2) {
            vector<int> curr;
            int columnIndex = i;
            for (int j = mat.size()-1; j >= 0 && columnIndex < mat[j].size(); j--) {
                curr.push_back(mat[j][columnIndex]);
                columnIndex++;
            }

            leftDiagonals.push_back(curr);
        }

        vector<vector<int>> rightDiagonals;
        // diagonals starting from first row
        for (int i = 1; i < mat[0].size(); i+=2) {
            vector<int> curr;
            for (int j = 0; j < mat.size() && (i-j) >= 0; j++) {
                curr.push_back(mat[j][i-j]);
            }

            rightDiagonals.push_back(curr);
        }

        // diagonals starting from last column
        index = 1;
        if (mat[0].size() % 2 == 0) {
            index = 2;
        }
        for (int i = index; i < mat.size(); i+=2) {
            vector<int> curr;
            int currIndex = i;
            for (int j = mat[0].size()-1; j >= 0 && currIndex < mat.size(); j--) {
                curr.push_back(mat[currIndex][j]);
                currIndex++;
            }

            rightDiagonals.push_back(curr);
        }

        vector<int> output;

        int i = 0;
        while (i < leftDiagonals.size() || i < rightDiagonals.size()) {
            if (i < leftDiagonals.size()) {
                for (int j = 0; j < leftDiagonals[i].size(); j++) {
                    output.push_back(leftDiagonals[i][j]);
                }
            }

            if (i < rightDiagonals.size()) {
                for (int j = 0; j < rightDiagonals[i].size(); j++) {
                    output.push_back(rightDiagonals[i][j]);
                }
            }

            i++;
        }

        return output;
    }
};