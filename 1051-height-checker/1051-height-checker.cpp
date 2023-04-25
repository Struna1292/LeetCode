class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int counter = 0;
        vector<int> check = heights;
        sort(begin(check), end(check));
        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != check[i])
            {
                counter++;
            }
        }
        return counter;
    }
};