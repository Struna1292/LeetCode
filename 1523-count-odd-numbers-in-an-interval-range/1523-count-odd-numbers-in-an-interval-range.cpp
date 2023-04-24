class Solution {
public:
    int countOdds(int low, int high) {
        int output = 0;
        if ((high - low + 1) % 2 == 0)
        {
            output = (high - low + 1) / 2;
        }
        else
        {
            output = (high - low) / 2;
            if (high % 2 != 0)
            {
                output++;
            }
        }
        return output;
    }
};