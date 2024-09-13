class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        
        vector<string> numString(3, "");

        numString[0] = to_string(num1);
        numString[1] = to_string(num2);
        numString[2] = to_string(num3);

        for (int i = 0; i < 3; i++)
        {
            while (numString[i].length() < 4)
            {
                numString[i] = "0" + numString[i];
            }
        }

        string num;

        for (int i = 0; i < 4; i++)
        {
            char lowest = '9';
            for (int j = 0; j < 3; j++)
            {
                if (numString[j][i] < lowest)
                {
                    lowest = numString[j][i];
                }
            }

            num.push_back(lowest);
        }

        return stoi(num);
    }
};