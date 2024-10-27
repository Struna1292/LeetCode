class Solution {
public:
    int helper(vector<int> nums, int aliceTotal, int bobTotal, int curr)
    {
        int left = 0;
        int right = nums.size()-1;


        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (aliceTotal-curr+nums[mid] == bobTotal-nums[mid]+curr)
            {
                return mid;
            }
            
            if (aliceTotal-curr+nums[mid] > bobTotal-nums[mid]+curr)
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

    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        
        int aliceTotal = 0;

        for (int i = 0; i < aliceSizes.size(); i++)
        {
            aliceTotal += aliceSizes[i];
        }

        int bobTotal = 0;

        for (int i = 0; i < bobSizes.size(); i++)
        {
            bobTotal += bobSizes[i];
        }

        sort(begin(bobSizes), end(bobSizes));

        vector<int> output;

        for (int i = 0; i < aliceSizes.size(); i++)
        {
            int index = helper(bobSizes, aliceTotal, bobTotal, aliceSizes[i]);
            if (index != -1)
            {
                output.push_back(aliceSizes[i]);
                output.push_back(bobSizes[index]);
                break;
            }
        }

        

        return output;
    }
};