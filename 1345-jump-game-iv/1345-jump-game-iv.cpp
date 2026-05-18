class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < arr.size(); i++) {
            um[arr[i]].push_back(i);
        }

        vector<bool> seen(arr.size(), false);
        unordered_map<int, bool> valueSeen;

        queue<int> que;
        que.push(0);

        int counter = 0;

        while (!que.empty()) {
            int size = que.size();
            while (size > 0) {
                size--;

                int i = que.front();
                que.pop();

                if (i < 0 || i >= arr.size() || seen[i]) {
                    continue;
                }

                if (i == arr.size()-1) {
                    return counter;
                }

                seen[i] = true;

                que.push(i + 1);
                que.push(i - 1);

                if (!valueSeen[arr[i]]) {
                    const vector<int>& indexes = um[arr[i]];
                    for (int j = 0; j < indexes.size(); j++) {
                        que.push(indexes[j]);
                    }

                    valueSeen[arr[i]] = true;
                }
            }

            counter++;
        }

        return counter;
    }
};