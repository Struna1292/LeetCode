class Solution {
public:
    bool canAliceWin(int n) {
        
        int currStones = 10;
        int i = 1;

        while (n >= 0)
        {
            n -= currStones;
            currStones--;
            i++;
        }

        if (i % 2 == 0)
        {
            return false;
        }
        return true;
    }
};