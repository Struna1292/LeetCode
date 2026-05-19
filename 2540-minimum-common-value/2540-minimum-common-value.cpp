class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us;
        for (int i = 0; i < nums1.size(); i++) {
            us.insert(nums1[i]);
        }

        int min = -1;
        for (int i = 0; i < nums2.size(); i++) {
            if ( (min == -1 || nums2[i] < min) && us.contains(nums2[i])) {
                min = nums2[i];
            }
        }

        return min;
    }
};