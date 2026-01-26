class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(begin(arr), end(arr));
        unordered_set<int> us;
        us.insert(arr[0]);

        int minDiff = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            us.insert(arr[i]);
            if (arr[i] - arr[i-1] < minDiff) {
                minDiff = arr[i] - arr[i-1];
            }
        }

        vector<vector<int>> output;
        for (int i = 0; i < arr.size(); i++) {
            int curr = arr[i] - minDiff;

            if (us.contains(curr)) {
                output.push_back({ curr, arr[i] });
            }
        }

        return output;
    }
};