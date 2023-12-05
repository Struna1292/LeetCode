class Solution {
public:
    int numberOfMatches(int n) {

        int output = 0;

        while (n > 1)
        {
            if (n % 2 != 0)
            {
                n--;
                n /= 2;
                output += n;
                n++;
            }
            else
            {
                n /= 2;
                output += n;
            }
        }

        return output;
    }
};