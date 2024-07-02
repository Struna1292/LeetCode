class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int arr1[1001] = { 0 };
        int arr2[1001] = { 0 };

        for (int i = 0; i < nums1.size(); i++)
        {
            arr1[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            arr2[nums2[i]]++;
        }

        vector<int> output;
        
        for (int i = 0; i < 1001; i++)
        {
            for (int j = 0; j < min(arr1[i], arr2[i]); j++)
            {
                output.push_back(i);
            }
        }

        return output;
    }
};