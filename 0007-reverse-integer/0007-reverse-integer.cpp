class Solution {
public:
    int reverse(int x) {
        long reversed = 0;
        while (x != 0)
        {
            reversed += x % 10;
            reversed *= 10;
            x /= 10;
        }
        reversed /= 10;
        int output = reversed;
        if (output == reversed)
        {
            return output;
        }
        return 0;
    }
};