class Solution {
public:
    int binarySearch(vector<pair<int,int>>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left)/2;

            if ((mid == 0 && nums[mid].first <= target) || (mid > 0 && nums[mid].first <= target && nums[mid-1].first > target))
            {
                return nums[mid].second;
            }

            if (nums[mid].first > target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }

        }
        return -1;
    }

    int maxWidthRamp(vector<int>& nums) {
        
        vector<pair<int,int>> heights;

        int output = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (heights.size() < 1 || heights[heights.size()-1].first > nums[i])
            {
                heights.push_back({nums[i], i});
            }
            else
            {   
                int index = binarySearch(heights, nums[i]);

                if (i - index > output)
                {
                    output = i - index;
                }
            }
        }

        return output;
    }
};