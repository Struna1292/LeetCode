class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int prev = -1;

        for (int i = 0; i < bits.size()-1; i++)
        {
            if (bits[i] == 0)
            {
                prev = -1;
            }
            else if (prev == -1)
            {
                prev = bits[i];
            }
            else if (prev == bits[i])
            {
                prev = -1;
            }
        }

        if (prev == -1)
        {
            return true;
        }

        return false;
    }
};