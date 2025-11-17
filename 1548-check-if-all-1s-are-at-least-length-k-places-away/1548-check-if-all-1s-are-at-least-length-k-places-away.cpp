class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int zerosCount = 0;
        bool prevOne = false;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zerosCount++;
                continue;
            }

            if (prevOne && zerosCount < k) {
                return false;
            }
            else {
                prevOne = true;
            }

            zerosCount = 0;
        }

        return true;
    }
};