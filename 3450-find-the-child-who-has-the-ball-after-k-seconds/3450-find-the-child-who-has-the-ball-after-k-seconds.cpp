class Solution {
public:
    int numberOfChild(int n, int k) {
        
        if (k < n)
        {
            return k;
        }
        n--;

        int move = k % n;
        int direction = k / n;

        int output = 0;

        if (direction % 2 == 0)
        {
            output += move;
        }
        else
        {
            output = n-move;
        }

        return output;
    }
};