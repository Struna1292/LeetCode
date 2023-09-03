class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        
        int counter = 0;

        for (int i = low; i <= high; i++)
        {
            string num = to_string(i);
            if (num.length() % 2 == 0)
            {
                int i = 0;
                int j = num.length()-1;
                int check = 0;
                while (i < j)
                {
                    check += (num[i] - '0');
                    check -= (num[j] - '0');
                    i++;
                    j--;
                }

                if (check == 0)
                {
                    counter++;
                }   
            }
        }

        return counter;
    }
};