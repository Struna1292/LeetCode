class Solution {
public:
    void DFS(int i, vector<int>& arr, vector<bool>& seen, bool& found) {
        if (i < 0 || i >= arr.size() || seen[i] || found) {
            return;
        }
        if (arr[i] == 0) {
            found = true;
            return;
        }
        seen[i] = true;

        DFS(i + arr[i], arr, seen, found);
        DFS(i - arr[i], arr, seen, found);
    }

    bool canReach(vector<int>& arr, int start) {
        bool found = false;
        vector<bool> seen(arr.size(), false);

        DFS(start, arr, seen, found);

        return found;
    }
};