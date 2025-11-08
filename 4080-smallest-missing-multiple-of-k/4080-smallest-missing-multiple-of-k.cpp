class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> us;

        for (int& num : nums) {
            us.insert(num);
        }

        int i = 1;
        while (true) {
            if (!us.contains(k*i)) {
                return k*i;
            }
            i++;
        }   

        return -1;
    }
};