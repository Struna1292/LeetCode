class Solution {
public:
    int minDistance(int startIndex, int endIndex, int size) {
        if (startIndex == endIndex) {
            return -1;
        }

        int forward = (endIndex - startIndex + size) % size;
        int backward = (startIndex - endIndex + size) % size;

        return min(forward, backward);
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> um;

        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]].push_back(i);
        }

        vector<int> output;

        for (int i = 0; i < queries.size(); i++) {
            int queryIndex = queries[i];
            int value = nums[queryIndex];
            const vector<int>& indexes = um[value];

            int nearestIndex = -1;

            int valueIndex = lower_bound(begin(indexes), end(indexes), queryIndex) - begin(indexes);

            int left = (valueIndex - 1 + indexes.size()) % indexes.size();
            int right = (valueIndex + 1) % indexes.size();
            int leftIndex = indexes[left];
            int rightIndex = indexes[right];

            int leftDistance = minDistance(queryIndex, leftIndex, nums.size());
            int rightDistance = minDistance(queryIndex, rightIndex, nums.size());

            if (leftDistance != -1 && rightDistance != -1) {
                output.push_back(min(leftDistance, rightDistance));
            }
            else if (leftDistance != -1) {
                output.push_back(leftDistance);
            }
            else {
                output.push_back(rightDistance);
            }
        }

        return output;
    }
};