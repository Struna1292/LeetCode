class NumArray {
public:
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        int sumRange = 0;

        left = left < 0 ? 0 : left;
        right = right > nums.size()-1 ? nums.size()-1 : right;
        
        for (int i = left; i <= right; i++)
        sumRange += nums[i];
        return sumRange;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */