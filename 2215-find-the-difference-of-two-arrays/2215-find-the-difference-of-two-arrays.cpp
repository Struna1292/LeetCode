class Solution {
public:

    void pushRest(int &i, vector<int> &nums, vector<int> &output)
    {
        for (i; i < nums.size(); i++)
        {
            output.push_back(nums[i]);
        }
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        sort(begin(nums1), end(nums1));
        nums1.erase(unique(begin(nums1), end(nums1)), end(nums1));

        sort(begin(nums2), end(nums2));
        nums2.erase(unique(begin(nums2), end(nums2)), end(nums2));

        int i = 0;
        int j = 0;

        vector<int> curr1;
        vector<int> curr2;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] > nums2[j])
            {
                curr2.push_back(nums2[j]);
                j++;
            }
            else if (nums2[j] > nums1[i])
            {
                curr1.push_back(nums1[i]);
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }

        if (i == nums1.size())
        {
            pushRest(j, nums2, curr2);
        }
        else if (j == nums2.size())
        {
            pushRest(i, nums1, curr1);
        }

        vector<vector<int>> output;
        output.push_back(curr1);
        output.push_back(curr2);

        return output;
    }
};