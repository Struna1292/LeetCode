class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if (coordinates[0] % 2 != 0)
        {
            if (coordinates[1] % 2 != 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        if (coordinates[1] % 2 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};