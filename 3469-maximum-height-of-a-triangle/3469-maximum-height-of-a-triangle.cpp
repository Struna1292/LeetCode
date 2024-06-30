class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {

        int currentRow = 1;

        int red1 = red;
        int blue1 = blue;

        while (true)
        {
            if (currentRow % 2 != 0)
            {
                if (blue1 >= currentRow)
                {
                    blue1 -= currentRow;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (red1 >= currentRow)
                {
                    red1 -= currentRow;
                }
                else
                {
                    break;
                }
            }
            currentRow++;
        }

        int output = currentRow;

        currentRow = 1;

        red1 = red;
        blue1 = blue;

        while (true)
        {
            if (currentRow % 2 != 0)
            {
                if (red1 >= currentRow)
                {
                    red1 -= currentRow;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (blue1 >= currentRow)
                {
                    blue1 -= currentRow;
                }
                else
                {
                    break;
                }
            }
            currentRow++;
        }

        if (currentRow > output)
        {
            output = currentRow;
        }


        return output-1;
    }
};