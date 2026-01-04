class Solution {
public:
    struct Info {
        int counter;
        int sum;
        Info(int c, int s) {
            counter = c;
            sum = s;
        }
        Info() {}
    };

    int sumFourDivisors(vector<int>& nums) {
        int output = 0;
        unordered_map<int, Info> um;

        for (int i = 0; i < nums.size(); i++) {

            if (um.contains(nums[i])) {

                if (um[nums[i]].counter == 4) {
                    output += um[nums[i]].sum;
                }

                continue;
            }

            int counter = 0;
            int currSum = 0;
            for (int j = sqrt(nums[i]); j >= 1; j--) {
                if (nums[i] % j == 0) {
                    counter++;
                    currSum += j;
                    if (nums[i] / j != j) {
                        counter++;
                        currSum += (nums[i] / j);
                    }
                }
                if (counter > 4) {
                    break;
                }
            }

            if (counter == 4) {
                output += currSum;
            }
            um[nums[i]] = Info(counter, currSum);
        }

        return output;
    }   
};