class Solution {
public:
    string largestGoodInteger(string num) {
        string output = "";

        for (int i = 1; i < num.length()-1; i++)
        {
            if (num[i-1] == num[i] && num[i] == num[i+1])
            {
                if (output == "")
                {
                    for (int j = 0; j < 3; j++)
                    {
                        output.push_back(num[i]);
                    }
                }
                else
                {
                    if (output[0] < num[i])
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            output[j] = num[i];
                        }
                    }
                }
            }
        }

        return output;
    }
};