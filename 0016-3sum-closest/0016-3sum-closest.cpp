class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(begin(nums), end(nums));

        int closest = 0;

        for (int i = 0; i < nums.size()-2; i++)
        {
            int j = i+1;
            int k = nums.size()-1;

            if (i == 0)
            {
                closest = nums[i] + nums[j] + nums[k];
            }

            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == target)
                {
                    return target;
                }

                if (abs(target - closest) > abs(target - (nums[i] + nums[j] + nums[k])))
                {
                    closest = nums[i] + nums[j] + nums[k];
                }

                if (nums[i] + nums[j] + nums[k] > target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }

        return closest;
    }
};