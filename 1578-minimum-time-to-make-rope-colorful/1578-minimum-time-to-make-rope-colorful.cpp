class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int output = 0;
        
        char prevColor = colors[0];
        int prevTime = neededTime[0];

        for (int i = 1; i < colors.length(); i++)
        {
            if (colors[i] == prevColor)
            {
                if (prevTime < neededTime[i])
                {
                    output += prevTime;
                    prevColor = colors[i];
                    prevTime = neededTime[i];
                }
                else
                {
                    output += neededTime[i];
                }
            }
            else
            {
                prevColor = colors[i];
                prevTime = neededTime[i];
            }
        }
        
        return output;
    }
};