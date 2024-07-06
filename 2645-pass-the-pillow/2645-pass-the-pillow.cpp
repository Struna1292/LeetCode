class Solution {
public:
    int passThePillow(int n, int time) {
        
        if (time < n)
        {   
            return time+1;
        }

        int direction = time / (n-1);

        int moves = time % (n-1);

        if (direction % 2 == 0) // starting from left
        {
            return moves+1;
        }
        // starting from right

        return n-moves;
    }
};