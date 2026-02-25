class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> um;

        for (int i = 0; i < arr.size(); i++) {
            if (!um.contains(arr[i])) {
                int curr = arr[i];
                while (curr > 0) {
                    if ((curr & 1) == 1) {
                        um[arr[i]]++;
                    }
                    curr >>= 1;
                }
            }
        }

        sort(begin(arr), end(arr), [&](int a, int b) {
            if (um[a] == um[b]) {
                return a < b;
            }
            return um[a] < um[b];
        });

        return arr;
    }
};