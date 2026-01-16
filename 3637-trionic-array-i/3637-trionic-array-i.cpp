class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        
        int i = nums.size()-1;
        bool check = false;

        while (i > 0) {
            if (nums[i-1] == nums[i]) {
                return false;
            }
            else if (nums[i-1] < nums[i]) {
                check = true;
            }
            else {
                break;
            }
            i--;
        }
        if (!check) { return false; }

        check = false;
        while (i > 0) {
            if (nums[i-1] == nums[i]) {
                return false;
            }
            else if (nums[i-1] > nums[i]) {
                check = true;
            }
            else {
                break;
            }
            i--;
        }
        if (!check) { return false; }

        check = false;
        while (i > 0) {
            if (nums[i-1] == nums[i]) {
                return false;
            }
            else if (nums[i-1] < nums[i]) {
                check = true;
            }
            else {
                break;
            }
            i--;
        }
        if (i != 0) {
            return false;
        }

        return check;
    }
};