class Solution {
public:
    bool binarySearch(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return true;
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

        return false;
    }

    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        sort(begin(nums3), end(nums3));

        vector<int> output;

        for (int i = 0; i < nums1.size(); i++)
        {
            if (binarySearch(nums2, nums1[i]) || binarySearch(nums3, nums1[i]))
            {
                if (binarySearch(output, nums1[i]) == false)
                {
                    output.push_back(nums1[i]);
                    sort(begin(output), end(output));
                }
            }
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (binarySearch(nums1, nums2[i]) || binarySearch(nums3, nums2[i]))
            {
                if (binarySearch(output, nums2[i]) == false)
                {
                    output.push_back(nums2[i]);
                    sort(begin(output), end(output));
                }
            }
        }

        for (int i = 0; i < nums3.size(); i++)
        {
            if (binarySearch(nums1, nums3[i]) || binarySearch(nums2, nums3[i]))
            {
                if (binarySearch(output, nums3[i]) == false)
                {
                    output.push_back(nums3[i]);
                    sort(begin(output), end(output));
                }
            }
        }

        return output;
    }
};