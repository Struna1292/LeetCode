class Solution {
public:
    int minSwaps(string s) {
        
        int leftBrackets = 0;

        int j = s.length()-1;

        int swaps = 0;

        for (int i = 0; i < s.length()-1; i++)
        {
            if (i >= j)
            {
                break;
            }

            if (s[i] == '[')
            {
                leftBrackets++;
            }
            else
            {
                if (leftBrackets > 0)
                {
                    leftBrackets--;
                }
                else
                {
                    for (; j > i; j--)
                    {
                        if (s[j] == '[')
                        {
                            swap(s[i], s[j]);
                            leftBrackets++;
                            swaps++;
                            break;
                        }
                    }
                }
            }
        }

        return swaps;
    }
};