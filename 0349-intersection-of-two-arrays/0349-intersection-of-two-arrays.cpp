class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));

        vector<int> output;

        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                if (output.size() == 0 || nums1[i] != output[output.size()-1])
                {
                    output.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }

        return output;
    }
};