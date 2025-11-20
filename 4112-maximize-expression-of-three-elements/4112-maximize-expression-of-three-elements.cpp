class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int a = nums[0];
        int b = -200;
        int c = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > a) {
                b = a;
                a = nums[i];
            }
            else if (nums[i] > b) {
                b = nums[i];
            }

            if (nums[i] < c) {
                c = nums[i];
            }
        }

        return a + b - c;
    }
};