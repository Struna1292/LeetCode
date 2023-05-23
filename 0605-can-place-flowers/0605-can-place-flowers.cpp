class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0)
        {
            return true;
        }

        int counter = 0;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0)
            {
                int prev = 0;
                if (i > 0)
                {
                    prev = flowerbed[i-1];
                }

                int next = 0;
                if (i < flowerbed.size()-1)
                {
                    next = flowerbed[i+1];
                }

                if (prev == 0 && next == 0)
                {
                    counter++;
                    flowerbed[i] = 1;
                }

            }
        }

        if (counter >= n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};