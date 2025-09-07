class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int> nums(n, 0);

        int currValue = (n / 2) * -1;

        for (int i = 0; i < nums.size(); i++, currValue++) {
            if (currValue == 0 && n % 2 == 0) {
                currValue++;
            }
            nums[i] = currValue;
        }

        return nums;
    }
};