class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int output = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int value = nums1[i];

            auto idx = upper_bound(begin(nums2), end(nums2), value, greater<int>()) - begin(nums2);

            idx--;

            if (idx < i) {
                continue;
            }

            if (abs(idx - i) > output) {
                output = abs(idx - i);
            }
        }

        return output;
    }
};