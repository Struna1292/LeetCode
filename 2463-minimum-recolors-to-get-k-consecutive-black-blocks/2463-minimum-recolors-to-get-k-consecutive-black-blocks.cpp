class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int currW = 0;
        int currB = 0;

        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
            {
                currW++;
            }
            else
            {
                currB++;
            }
        }

        int output = currW;

        for (int i = k; i < blocks.length(); i++)
        {
            if (blocks[i-k] == 'W')
            {
                currW--;
            }
            else
            {
                currB--;
            }

            if (blocks[i] == 'W')
            {
                currW++;
            }
            else
            {
                currB++;
            }

            if (currW < output)
            {
                output = currW;
            }
        }

        return output;
    }
};