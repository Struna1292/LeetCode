class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int, int> um;
        int smallest = nums[0];
        int biggest = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
            smallest = min(smallest, nums[i]);
            biggest = max(biggest, nums[i]);
        }

        vector<int> output;
        for (int i = smallest; i <= biggest; i++) {
            if (um[i] == 0) {
                output.push_back(i);
            }
        }

        return output;
    }
};