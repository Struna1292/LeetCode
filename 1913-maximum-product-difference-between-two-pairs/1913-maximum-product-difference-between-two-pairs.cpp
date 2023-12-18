class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int s1 = 10001;
        int s2 = 10001;

        int b1 = 0;
        int b2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > b1)
            {
                b2 = b1;
                b1 = nums[i];
            } 
            else if (nums[i] > b2)
            {
                b2 = nums[i];
            }

            if (nums[i] < s1)
            {
                s2 = s1;
                s1 = nums[i];
            } 
            else if (nums[i] < s2)
            {
                s2 = nums[i];
            }
        }

        cout << b1 << " * " << b2 << " - " << s1 << " * " << s2 << endl;
        return b1 * b2 - s1 * s2;
    }
};