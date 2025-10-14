class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k == 1) {
            return true;
        }

        int currK = k-1;
        unordered_set<int> indexes;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                if (currK > 0) {
                    currK--;
                }

                if (currK == 0) {
                    if (indexes.find(i-k) != indexes.end()) {
                        return true;
                    }
                    else {
                        indexes.insert(i);
                    }
                }
            }
            else {
                currK = k-1;
            }
        }

        return false;
    }
};