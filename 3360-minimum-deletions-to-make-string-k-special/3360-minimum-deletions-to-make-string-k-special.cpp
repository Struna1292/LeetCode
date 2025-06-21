class Solution {
public:
    int minimumDeletions(string word, int k) {
        
        vector<int> freq(26, 0);

        for (char c : word) {
            freq[c-'a']++;
        }

        vector<int> nums;

        for (int n : freq) {
            if (n > 0) {
                nums.push_back(n);
            }
        }

        int output = -1;

        for (int i = 0; i < nums.size(); i++) {

            int currScore = 0;
            for (int j = 0; j < nums.size(); j++) {

                if (nums[j] < nums[i]) {
                    currScore += nums[j];
                } else if (nums[j] > nums[i]+k) {
                    currScore += nums[j] - (nums[i]+k);
                }

                if (currScore > output && output != -1) {
                    break;
                }
            }

            if (currScore < output || output == -1) {
                output = currScore;
            }
        }

        return output;
    }
};