class Solution {
public:
    int binarySearch(vector<pair<int,int>>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {   
            int mid = left + (right - left) / 2;

            if (nums[mid].first == target)
            {
                return mid;
            }

            if (nums[mid].first > target)
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

    int maxSubarrayLength(vector<int>& nums, int k) {
        vector<int> numsCopy = nums;

        sort(begin(numsCopy), end(numsCopy));

        vector<pair<int,int>> numsFreq;

        int prev = numsCopy[0];

        for (int i = 1; i < numsCopy.size(); i++)
        {
            if (numsCopy[i] != prev)
            {
                numsFreq.push_back({prev, 0});
                prev = numsCopy[i];
            }
        }
        numsFreq.push_back({prev, 0});

        int output = 0;

        int i = 0;
        int j = 0;

        while (i < nums.size())
        {
            int index = binarySearch(numsFreq, nums[i]);

            if (numsFreq[index].second == k)
            {
                while (nums[j] != nums[i])
                {
                    numsFreq[binarySearch(numsFreq, nums[j])].second--;
                    j++;
                }
                j++;
            }
            else
            {
                numsFreq[index].second++;
            }
            i++;

            if (i - j > output)
            {
                output = i - j;
            }
        }

        return output;
    }
};