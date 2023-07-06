class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        int counter = 0;
        while ((a != 0 && b != 0) || (a != 0 && c != 0) || (b != 0 && c != 0))
        {
            counter++;
            if (a == 0)
            {
                b--;
                c--;
            }
            else if (b == 0)
            {
                a--;
                c--;
            }
            else if (c == 0)
            {
                a--;
                b--;
            }
            else if (a > b && a > c)
            {
                a--;
                if (b > c)
                {
                    b--;
                }
                else
                {
                    c--;
                }
            }
            else if (b > a && b > c)
            {
                b--;
                if (a > c)
                {
                    a--;
                }
                else
                {
                    c--;
                }
            }
            else if (c > a && c > b)
            {
                c--;
                if (a > b)
                {
                    a--;
                }
                else
                {
                    b--;
                }
            }
            else
            {
                a--;
                b--;
            }
        }
        return counter;
    }
};