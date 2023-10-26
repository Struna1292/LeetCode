class Solution {
public:
    int addTwoPositive(int a, int b)
    {
        if (a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        string num1;
        string num2;

        while (a > 0)
        {
            num1.push_back((a & 1) + '0');
            a >>= 1;
        }

        while (b > 0)
        {
            num2.push_back((b & 1) + '0');
            b >>= 1;
        }

        int zeros = num1.length() - num2.length();

        for (int i = 0; i < zeros; i++)
        {
            num2.push_back('0');
        }
        
        string outputBin;

        int remainder = 0;
        for (int i = 0; i < num1.length(); i++)
        {
            int currOnes = 0;

            if (num1[i] == '1')
                currOnes++;

            if (num2[i] == '1')
                currOnes++;

            if (remainder == 1)
            {
                currOnes++;
                remainder = 0;
            }

            if (currOnes == 0)
            {
                outputBin.push_back('0');
            }
            else if (currOnes == 1)
            {
                outputBin.push_back('1');
            }
            else if (currOnes == 2)
            {
                outputBin.push_back('0');
                remainder = 1;
            }
            else
            {
                outputBin.push_back('1');
                remainder = 1;
            }
        }

        if (remainder == 1)
        {
            outputBin.push_back('1');
        }

        int output = 0;

        for (int j = outputBin.length()-1; j >= 0; j--)
        {
            output |= (outputBin[j]-'0');
            if (j != 0)
                output <<= 1;
        }

        return output;
    }

    int addTwoNegative(int a, int b)
    {
        return addTwoPositive(a * -1, b * -1) * -1;
    }

    int addPositiveNegative(int a, int b)
    {
        string num1;
        string num2;

        a *= -1;

        if (a == b)
        {
            return 0;
        }

        bool negative = false;

        if (a > b)
        {
            negative = true;
        }
        else
        {
            int temp = a;
            a = b;
            b = temp;
        }


        while (a > 0)
        {
            num1.push_back((a & 1) + '0');
            a >>= 1;
        }


        while (b > 0)
        {
            num2.push_back((b & 1) + '0');
            b >>= 1;
        }


        if (num1.length() > num2.length())
        {
            int zeros = num1.length() - num2.length();
            for (int i = 0; i < zeros; i++)
            {
                num2.push_back('0');
            }
        }
        else if (num1.length() < num2.length())
        {
            int zeros = num2.length() - num1.length();
            for (int i = 0; i < zeros; i++)
            {
                num1.push_back('0');
            }
        }

        string outputBin;

        for (int i = 0; i < num1.length(); i++)
        {
            if (num1[i] == '1' && num2[i] == '1' || num1[i] == '0' && num2[i] == '0')
            {
                outputBin.push_back('0');
            }
            else if (num1[i] == '1' && num2[i] == '0')
            {
                outputBin.push_back('1');
            }
            else
            {
                int j = i+1;
                while (num1[j] == '0')
                {
                    num1[j] = '1';
                    j++;
                }

                num1[j] = '0';
                outputBin.push_back('1');
            }
        }

        int output = 0;

        int j = outputBin.length()-1;

        while (outputBin[j] == '0')
        {
            j--;
        }

        for (j; j >= 0; j--)
        {
            output |= (outputBin[j]-'0');
            if (j != 0)
                output <<= 1;
        }

        if (negative)
        {
            output *= -1;
        }
        
        return output;
    }

    int getSum(int a, int b) {
        int output = 0;

        if (a >= 0 && b >= 0)
        {
            output = addTwoPositive(a, b);
        }
        else if (a < 0 && b < 0)
        {
            output = addTwoNegative(a, b);
        }
        else
        {
            if (a < 0)
            {
                output = addPositiveNegative(a, b);
            }
            else
            {
                output = addPositiveNegative(b, a);
            }
        }

        
        return output;
    }
};