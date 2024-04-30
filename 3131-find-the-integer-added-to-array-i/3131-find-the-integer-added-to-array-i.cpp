class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {

        int min1 = nums1[0];
        int min2 = nums2[0];

        for (int i = 1; i < nums1.size(); i++)
        {
            if (nums1[i] < min1)
            {
                min1 = nums1[i];
            }

            if (nums2[i] < min2)
            {
                min2 = nums2[i];
            }
        }
    
        
        return min2 - min1;
    }
};