class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(begin(nums), end(nums));

        int n = nums.size();

        int mid = 0;

        if (n % 2 == 0)
        {
            mid = (n / 2) - 1;
        }
        else
        {
            mid = n / 2;
        }

        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            counter += abs(nums[i] - nums[mid]);
        }
        
        return counter;
    }
};