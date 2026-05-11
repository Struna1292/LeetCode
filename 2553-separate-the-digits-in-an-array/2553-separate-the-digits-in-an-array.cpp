class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> output;

        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);

            for (int j = 0; j < s.length(); j++) {
                output.push_back(s[j]-'0');
            }
        }

        return output;
    }
};