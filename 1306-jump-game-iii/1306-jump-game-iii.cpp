class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> seen(arr.size(), false);

        queue<int> que;
        que.push(start);

        while (!que.empty()) {
            int i = que.front();
            que.pop();

            if (i < 0 || i >= arr.size() || seen[i]) {
                continue;
            }

            seen[i] = true;

            if (arr[i] == 0) {
                return true;
            }
            else {
                que.push(i - arr[i]);
                que.push(i + arr[i]);
            }
        }

        return false;
    }
};