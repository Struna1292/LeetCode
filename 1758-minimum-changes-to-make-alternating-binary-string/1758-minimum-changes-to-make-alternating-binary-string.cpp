class Solution {
public:
    int minOperations(string s) {  
        
        int counter1 = 0; // sequence starting with 1
        int counter2 = 0; // sequence starting with 0

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                if ((i+1) % 2 == 1)
                {
                    counter2++;
                }
                else
                {
                    counter1++;
                }
            }
            else
            {
                if ((i+1) % 2 == 1)
                {
                    counter1++;
                }
                else
                {
                    counter2++;
                }
            }
        }
        
        if (counter1 < counter2)
        {
            return counter1;
        }

        return counter2;
    }
};