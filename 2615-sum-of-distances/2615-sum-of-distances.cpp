class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> indexes;
        unordered_map<int, long long> indexSum;

        for (int i = 0; i < nums.size(); i++) {
            indexes[nums[i]].push_back(i);
            indexSum[nums[i]] += i;
        }

        vector<long long> output(nums.size(), 0);
        for (auto itr = indexes.begin(); itr != indexes.end(); itr++) {
            const vector<int>& currIndexes = itr->second;
            long long total = indexSum[nums[currIndexes[0]]];

            int leftAmount = 0;
            int rightAmount = currIndexes.size() - 1;

            long long currSum = 0;
            for (int i = 0; i < currIndexes.size(); i++) {
                long long index = currIndexes[i];
                long long rest = total - currSum - index;

                output[index] = (index * leftAmount - currSum) + (rest - index * rightAmount);
                currSum += index;

                leftAmount++;
                rightAmount--;
            }
        }

        return output;
    }
};