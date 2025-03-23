class Solution {
public:
    int averageValue(vector<int>& nums) {
        
        int sum = 0;
        int counter = 0;

        for (int n : nums)
        {
            if (n % 6 == 0)
            {
                sum += n;
                counter++;
            }
        }

        if (counter == 0)
        {
            return 0;
        }

        return sum / counter;
    }
};