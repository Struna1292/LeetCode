class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> output;

        for (int j = 0; j < grid[0].size(); j++) {
            int longest = 0;
            for (int i = 0; i < grid.size(); i++) {
                string s = to_string(grid[i][j]);
                if (longest < s.length()) {
                    longest = s.length();
                }
            }
            output.push_back(longest);
        }

        return output;
    }
};