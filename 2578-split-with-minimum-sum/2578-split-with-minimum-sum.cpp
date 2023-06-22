class Solution {
public:
    int splitNum(int num) {

        string number = to_string(num);

        int nums[10] = { 0 };
        for (int i = 0; i < number.length(); i++)
        {
            if (number[i] != '0')
            {
                nums[number[i]-'0']++;
            }
        }

        string num1 = "0";
        string num2 = "0";

        for (int i = 1; i < 10; i++)
        {
            for (int j = 0; j < nums[i]; j++)
            {
                if (num2.length() > num1.length())
                {
                    num1.push_back(i + '0');
                }
                else
                {
                    num2.push_back(i + '0');
                }
            }
        }

        return stoi(num1) + stoi(num2);
    }
};