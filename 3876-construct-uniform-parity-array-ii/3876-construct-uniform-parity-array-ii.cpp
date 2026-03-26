class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> odd;

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 != 0) {
                odd.push_back(nums1[i]);
            }
        }

        sort(begin(odd), end(odd));

        bool allEven = true;
        for (int i = nums1.size()-1; i >= 0; i--) {
            if (nums1[i] % 2 == 0) { continue; }

            int index = lower_bound(begin(odd), end(odd), nums1[i]) - odd.begin();

            if (index-1 < 0) {
                allEven = false;
                break;
            }
        }

        bool allOdd = true;
        for (int i = nums1.size()-1; i >= 0; i--) {
            if (nums1[i] % 2 != 0) { continue; }

            int index = lower_bound(begin(odd), end(odd), nums1[i]) - odd.begin();

            if (index-1 < 0) {
                allOdd = false;
                break;
            }
        }        

        return allEven || allOdd;
    }
};