class Solution {
public:
    int numberOfOperations(int num)
    {
        int operations = 0;

        while (num > 0)
        {
            operations++;
            if (num - 60 >= 0)
            {
                num -= 60;
            }
            else if (num - 15 >= 0)
            {
                num -= 15;
            }
            else if (num - 5 >= 0)
            {
                num -= 5;
            }   
            else
            {
                num -= 1;
            }
        }

        return operations;
    }

    int convertTime(string current, string correct) {

        int currHours = (current[0] - '0') * 10 + current[1] - '0';
        int currMins = (current[3] - '0') * 10 + current[4] - '0';

        int corrHours = (correct[0] - '0') * 10 + correct[1] - '0';
        int corrMins = (correct[3] - '0') * 10 + correct[4] - '0';

        int totalCurrentMins = currHours * 60 + currMins;

        int totalCorrectMins = corrHours * 60 + corrMins;

        return numberOfOperations(totalCorrectMins - totalCurrentMins);
    }
};