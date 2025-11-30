class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        int k = 0;
        vector<int> seen;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == -1) {
                if (k < seen.size()) {
                    ans.push_back(seen[seen.size() - k - 1]);
                }
                else {
                    ans.push_back(-1);
                }

                k++;
            }
            else {
                seen.push_back(nums[i]);
                k = 0;
            }
        }

        return ans;
    }
};