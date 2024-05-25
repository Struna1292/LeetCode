class Solution {
public:
    int findNthDigit(int n) {
        // there is 9 one digit numbers, 90 two digit numbers, 900 three digit numbers and so on

        if (n <= 9)
        {
            return n;
        }

        int currDigits = 2;

        long currSum = 189;

        long currAmountOfNumbers = 90;

        while (n > currSum)
        {
            currDigits++;
            currAmountOfNumbers *= 10;
            currSum += (currAmountOfNumbers * currDigits);
        }

        int start = 1 * pow(10, currDigits-1);

        int digitsLeft = n - (currSum - (currAmountOfNumbers * currDigits));

        start += (ceil(((double)digitsLeft / currDigits))-1);

        string num = to_string(start);

        if ((digitsLeft % currDigits) == 0)
        {
            return num[num.length()-1]-'0';
        }

        return num[(digitsLeft % currDigits)-1]-'0';
    }
};