class Solution {
public:
    bool check(vector<int>& nums) {
        int breakPoints = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                breakPoints++;
            }
        }

        if (nums[0] < nums[nums.size()-1]) {
            breakPoints++;
        }

        return breakPoints <= 1;
    }
};