class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> indexes;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                indexes.push_back(i);
            }
        }
        
        if (indexes.size() == 0) {
            return nums;
        }

        int shiftsCount = k % indexes.size();
        vector<int> output = nums;
        for (int i = 0; i < indexes.size(); i++) {
            int currIndex = indexes[i];
            int shiftedIndex = indexes[(i + shiftsCount) % indexes.size()];

            output[currIndex] = nums[shiftedIndex];
        }

        return output;
    }
};