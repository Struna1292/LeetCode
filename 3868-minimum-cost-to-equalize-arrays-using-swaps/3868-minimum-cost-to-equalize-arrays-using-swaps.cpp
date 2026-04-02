class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> total;
        unordered_map<int, int> um1;

        for (int i = 0; i < nums1.size(); i++) {
            um1[nums1[i]]++;
            total[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++) {
            total[nums2[i]]++;
        }

        int totalCost = 0;
        for (auto itr = total.begin(); itr != total.end(); itr++) {
            if (itr->second % 2 != 0) {
                return -1;
            }

            int properAmount = itr->second / 2;

            totalCost += abs(um1[itr->first] - properAmount);
        }

        return totalCost / 2;
    }
};