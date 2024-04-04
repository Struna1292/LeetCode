class Solution {
public:
    int maxDepth(string s) {
        int counter = 0;

        int biggest = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                counter++;

                if (counter > biggest)
                {
                    biggest = counter;
                }
            }
            else if (s[i] == ')')
            {
                counter--;
            }
        }

        return biggest;
    }
};