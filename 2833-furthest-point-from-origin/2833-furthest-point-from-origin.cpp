class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int start = 0;
        int start1 = 0;

        for (int i = 0; i < moves.length(); i++)
        {
            if (moves[i] == 'L')
            {
                start--;
                start1--;
            }
            else if (moves[i] == 'R')
            {
                start++;
                start1++;
            }
            else
            {
                start--;
                start1++;
            }
        }

        if (start < 0)
        {
            start *= -1;
        }

        if (start1 < 0)
        {
            start1 *= -1;
        }

        return max(start,start1);
    }
};