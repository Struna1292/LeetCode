class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> us;

        for (int& num : nums) {
            us.insert(num);
        }

        int curr = k;
        while (true) {
            if (!us.contains(curr)) {
                return curr;
            }
            curr += k;
        }   

        return -1;
    }
};