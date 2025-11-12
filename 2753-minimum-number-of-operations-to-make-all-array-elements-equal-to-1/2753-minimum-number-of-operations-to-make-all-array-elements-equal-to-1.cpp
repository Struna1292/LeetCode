class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        // first find 1 or the gcd to 1
        // if there is no 1 and cant make gcd to 1 return -1
        bool possibleOne = false;
        int output = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (!possibleOne && i > 0 && gcd(nums[i-1], nums[i]) == 1) {
                possibleOne = true;
            }
            
            if (nums[i] != 1) {
                output++;
            }
            else {
                possibleOne = true;
            }
        }

        if (possibleOne) {
            return output;
        }

        int bestCounter = -1;
        for (int i = 1; i < nums.size(); i++) {
            int prev = -1;
            int counter = 0;
            for (int j = i; j < nums.size(); j++) {
                counter++;
                if (prev == -1) {
                    prev = gcd(nums[j-1], nums[j]);
                }
                else {
                    prev = gcd(prev, nums[j]);
                }

                if (prev == 1) {
                    possibleOne = true;
                    if (bestCounter == -1) {
                        bestCounter = counter;
                    }
                    else {
                        bestCounter = min(bestCounter, counter);
                    }
                    break;
                }
            }
        }

        if (!possibleOne) {
            return -1;
        }

        return output + bestCounter - 1;
    }
};