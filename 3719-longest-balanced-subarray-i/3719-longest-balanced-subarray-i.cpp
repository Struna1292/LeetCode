class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        for (int length = nums.size(); length >= 2; length--) {
            unordered_map<int, int> even;
            unordered_map<int, int> odd;

            for (int i = 0; i < length; i++) {
                if (nums[i] % 2 == 0) {
                    even[nums[i]]++;
                }
                else {
                    odd[nums[i]]++;
                }
            }

            if (even.size() == odd.size()) {
                return length;
            }

            for (int i = length; i < nums.size(); i++) {
                if (nums[i] % 2 == 0) {
                    even[nums[i]]++;
                }
                else {
                    odd[nums[i]]++;
                }

                if (nums[i-length] % 2 == 0) {
                    even[nums[i-length]]--;
                    if (even[nums[i-length]] == 0) {
                        even.erase(even.find(nums[i-length]));
                    }
                }
                else {
                    odd[nums[i-length]]--;
                    if (odd[nums[i-length]] == 0) {
                        odd.erase(odd.find(nums[i-length]));
                    }
                }

                if (even.size() == odd.size()) {
                    return length;
                }
            }
        }

        return 0;
    }
};