class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> output;
        int equal = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                output.push_back(nums[i]);
            }
            else if (nums[i] == pivot) {
                equal++;
            }
        }

        for (int i = 0; i < equal; i++) {
            output.push_back(pivot);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > pivot) {
                output.push_back(nums[i]);
            }
        }

        return output;
    }
};