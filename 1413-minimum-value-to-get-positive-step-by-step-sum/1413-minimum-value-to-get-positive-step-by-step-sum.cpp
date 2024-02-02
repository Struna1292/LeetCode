class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int startValue = 0;

        int lowestPoint = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            startValue += nums[i];
            if (startValue < lowestPoint)
            {
                lowestPoint = startValue;
            }
        }

        if (lowestPoint <= 0)
        {
            return (lowestPoint * -1)+1; 
        }

        return 1;
    }
};