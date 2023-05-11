class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));

        int left = 0;
        int right = nums.size()-1;

        vector<int> output;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                output.push_back(mid);
                for (int i = mid-1; i >= 0; i--)
                {
                    if (nums[i] == target)
                    {
                        output.push_back(i);
                    }
                    else
                    {
                        break;
                    }
                }
                for (int i = mid+1; i < nums.size(); i++)
                {
                    if (nums[i] == target)
                    {
                        output.push_back(i);
                    }
                    else
                    {
                        break;
                    }
                }
                break;
            }
            
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        sort(begin(output), end(output));

        return output;
    }
};