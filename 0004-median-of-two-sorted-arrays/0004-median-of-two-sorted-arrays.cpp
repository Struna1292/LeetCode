class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> merged;
        merged.reserve(n+m);

        int i = 0;
        int j = 0;

        while (i < n && j < m)
        {
            if (nums1[i] < nums2[j])
            {
                merged.emplace_back(nums1[i]);
                i++;
            }
            else if (nums1[i] == nums2[j])
            {
                merged.emplace_back(nums1[i]);
                merged.emplace_back(nums2[j]);
                i++;
                j++;
            }
            else
            {
                merged.emplace_back(nums2[j]);
                j++;
            }
        }

        while (i < n)
        {
            merged.emplace_back(nums1[i]);
            i++;
        }

        while (j < m)
        {
            merged.emplace_back(nums2[j]);
            j++;
        }

        if ((n+m) % 2 == 0)
        {
            double output = ((double)merged[((n+m)/2)-1] + (double)merged[(n+m)/2])/2;
            return output;
        }
        else
        {
            return (double)merged[(n+m)/2];
        }

        return 0;
    }
};