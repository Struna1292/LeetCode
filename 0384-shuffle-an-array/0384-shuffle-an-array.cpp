class Solution {
public:
    vector<int> nums;
    vector<int> original;

    Solution(vector<int>& nums) {
        this->original = nums;
        this->nums = nums;
    }
    
    vector<int> reset() {
        nums = original;
        return original;
    }
    
    vector<int> shuffle() {
        random_shuffle(begin(nums), end(nums));
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */