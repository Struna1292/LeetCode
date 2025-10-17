class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {

        vector<int> lengths;
        int counter = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                counter++;
            }
            else {
                lengths.push_back(counter);
                counter = 1;
            }
        }
        lengths.push_back(counter);
        
        int currK = 1;
        for (int i = 1; i < lengths.size(); i++) {
            currK = max(currK, lengths[i-1]/2);
            currK = max(currK, lengths[i]/2);
            
            int common = min(lengths[i-1], lengths[i]);

            currK = max(currK, common);
        }

        if (lengths.size() == 1) {
            return nums.size()/2;
        }

        return currK;
    }
};