class Solution {
public:
    int countTriples(int n) {
        vector<int> nums;
        unordered_set<int> us;

        for (int i = 1; i <= n; i++) {
            int curr = i*i;
            us.insert(curr);
            nums.push_back(curr);
        }

        int output = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (us.contains(nums[i] + nums[j])) {
                    output += 2;
                }
            }
        }

        return output;
    }
};