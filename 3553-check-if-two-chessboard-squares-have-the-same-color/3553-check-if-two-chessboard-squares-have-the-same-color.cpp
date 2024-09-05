class Solution {
public:
    bool isWhite(string cords)
    {
        if (cords[0] % 2 != 0) // a c e g
        {
            if (cords[1] % 2 != 0)
            {
                return false;
            }
        }
        else // b d f h
        {
            if (cords[1] % 2 == 0)
            {
                return false;
            }
        }
        return true;
    }

    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        
        if (isWhite(coordinate1) == isWhite(coordinate2))
        {
            return true;
        }

        return false;
    }
};