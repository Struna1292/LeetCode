class Solution {
public:
    bool isBalanced(string s) {
        vector<int> nums(9, 0);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                return false;
            }

            nums[s[i]-'1']++;
            if (nums[s[i]-'1'] > s[i]-'0') {
                return false;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 || nums[i] == i+1) {
                continue;
            }
            return false;
        }

        return true;
    }

    int nextBeautifulNumber(int n) {

        int curr = n+1;
        while (true) {
            if (isBalanced(to_string(curr))) {
                return curr;
            }
            curr++;
        }

        return -1;
    }
};