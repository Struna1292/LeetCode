class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int currSum = neededTime[0];
        int currMax = currSum;
        char prev = colors[0];
        int counter = 1;
        int output = 0;

        for (int i = 1; i < colors.length(); i++) {
            if (colors[i] == prev) {
                counter++;
                currSum += neededTime[i];
                
                currMax = max(currMax, neededTime[i]);
            }
            else {
                if (counter > 1) {
                    output += currSum - currMax;
                }

                currSum = neededTime[i];
                currMax = currSum;
                
                counter = 1;
                prev = colors[i];
            }
        }
        if (counter > 1) {
            output += currSum - currMax;
        }

        return output;
    }
};