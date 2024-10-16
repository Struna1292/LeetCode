class Solution {
public:
    string reformatNumber(string number) {
        
        string digits;

        for (char c : number)
        {
            if (c >= '0' && c <= '9')
            {
                digits.push_back(c);
            }
        }

        int border = digits.length();

        if (border % 3 == 1)
        {
            border -= 4;
        }
        else if (border % 3 == 2)
        {
            border -= 2;
        }

        string output;

        for (int i = 0; i < border; i+= 3)
        {
            if (i != 0)
            {
                output.push_back('-');
            }
            for (int j = i; j < i+3; j++)
            {
                output.push_back(digits[j]);
            }
        }

        for (int i = border; i < digits.length(); i += 2)
        {
            if (i != 0)
            {
                output.push_back('-');
            }
            for (int j = i; j < i+2; j++)
            {
                output.push_back(digits[j]);
            }
        }

        return output;
    }
};