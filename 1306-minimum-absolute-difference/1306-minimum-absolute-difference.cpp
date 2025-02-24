class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(begin(arr), end(arr));

        int currDiff = abs(arr[0] - arr[1]);

        vector<vector<int>> output;

        for (int i = 1; i < arr.size(); i++)
        {
            if (abs(arr[i-1] - arr[i]) < currDiff)
            {
                currDiff = abs(arr[i-1] - arr[i]);
                output = {};
                output.push_back({arr[i-1], arr[i]});
            }
            else if (abs(arr[i-1] - arr[i]) == currDiff)
            {
                output.push_back({arr[i-1], arr[i]});
            }
        }

        return output;
    }
};