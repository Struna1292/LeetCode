class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> output;

        int r1 = nums1.size();
        int r2 = nums2.size();

        int i = 0;
        int j = 0;

        while (i < r1 && j < r2)
        {
            if (nums1[i][0] == nums2[j][0])
            {
                output.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            else if(nums1[i][0] < nums2[j][0])
            {
                output.push_back(nums1[i]);
                i++;
            }
            else
            {
                output.push_back(nums2[j]);
                j++;
            }
        }

        if (i < r1)
        {   
            for (i; i < r1; i++)
            {
                output.push_back(nums1[i]);
            }
        }   
        else if (j < r2)
        {
            for (j; j < r2; j++)
            {
                output.push_back(nums2[j]);
            }
        }

        return output;
    }
};