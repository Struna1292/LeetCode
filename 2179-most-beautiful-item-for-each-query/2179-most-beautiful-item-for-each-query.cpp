class Solution {
public:
    int binarySearch(vector<vector<int>>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if ((mid == nums.size()-1 && nums[mid][0] == target) || (mid < nums.size()-1 && nums[mid][0] == target && nums[mid+1][0] > target))
            {
                return mid;
            }
            
            
            if (nums[mid][0] <= target)
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

    int upperBound(vector<vector<int>>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;

        if (nums[0][0] > target)
        {
            return -1;
        }

        if (nums[right][0] < target)
        {
            return right;
        }

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (mid < nums.size()-1 && nums[mid][0] < target && nums[mid+1][0] > target)
            {
                return mid;
            }

            if (nums[mid][0] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        sort(begin(items), end(items));

        vector<int> currBiggest(items.size(), 0);

        int biggest = items[0][1];
        
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i][1] > biggest)
            {
                biggest = items[i][1];
            }
            currBiggest[i] = biggest;
        }


        vector<int> output;

        for (int i = 0; i < queries.size(); i++)
        {
            int index = binarySearch(items, queries[i]);

            if (index == -1)
            {
                index = upperBound(items, queries[i]);
                if (index == -1)
                {
                    output.push_back(0);
                }
                else
                {
                    output.push_back(currBiggest[index]);
                }
            }
            else
            {
                output.push_back(currBiggest[index]);
            }
        }

        return output;
    }
};