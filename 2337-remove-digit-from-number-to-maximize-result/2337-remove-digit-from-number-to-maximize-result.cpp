class Solution {
public:
    string removeDigit(string number, char digit) {
        
        int prev = -1;

        for (int i = 0; i < number.length(); i++)
        {
            if (number[i] == digit && (i+1) < number.length() && number[i] < number[i+1])
            {
                prev = i;
                break;
            }
            else if (number[i] == digit)
            {
                prev = i;
            }
        }

        number.erase(number.begin() + prev);

        return number;
    }
};