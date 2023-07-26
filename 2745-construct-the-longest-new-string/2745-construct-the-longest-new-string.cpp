class Solution {
public:
    int longestString(int x, int y, int z) {
        int output = z * 2;

        if (x > y)
        {
            output += (y * 4) + 2;
        }
        else if (y > x)
        {
            output += (x * 4) + 2;
        }
        else
        {
            output += y * 4;
        }

        return output;
    }
};