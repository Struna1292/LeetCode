class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        
        sort(begin(nums), end(nums));

        int i = 0;
        int j = nums.size()-1;

        vector<float> averages((nums.size()/2), 0);

        float lowest = 0;

        int k = 0;
        while (i < j)
        {
            averages[k] = (float)(nums[i] + nums[j]) / 2;

            if (k == 0 || averages[k] < lowest)
            {
                lowest = averages[k];
            }

            i++;
            j--;
            k++;
        }

        return lowest;
    }
};