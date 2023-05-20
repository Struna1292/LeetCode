class Solution {
public:
    string add(string &num1, string &num2)
    {
        string sum;

        if (num1.length() > num2.length())
        {
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }

        bool one = false;
        int j = num1.length()-1;
        for (int i = num2.length()-1; i >= 0; i--)
        {
            int num = 0;
            if (j >= 0)
            {
                num = (num2[i] - '0') + (num1[j] - '0');
            }
            else
            {
                num = num2[i] - '0';
            }

            if (one)
            {
                num++;
                one = false;
            }
            if (num > 9)
            {
                num -= 10;
                one = true;
            }

            sum.append(to_string(num));

            j--;
        }

        if (one)
        {
            sum.push_back('1');
        }

        int i = 0;
        j = sum.length()-1;
        while (i < j)
        {
            swap(sum[i], sum[j]);
            i++;
            j--;
        }

        return sum;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        vector<string> nums;

        if (num1.length() > num2.length())
        {
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }

        int counter = 0;
        for (int i = num1.length()-1; i >= 0; i--)
        {
            string curr;
            int rest = 0;
            for (int j = num2.length()-1; j >= 0; j--)
            {
                int num = (num1[i] - '0') * (num2[j] - '0');
                num += rest;
                rest = 0;
                if (num > 9)
                {
                    rest = num / 10;
                    num -= rest * 10;
                }

                curr.push_back(num + '0');
            }

            if(rest > 0)
            {
                curr.push_back(rest + '0');
            }

            int k = 0;
            int l = curr.length()-1;
            while (k < l)
            {
                swap(curr[k], curr[l]);
                k++;
                l--;
            }

            for (k = 0; k < counter; k++)
            {
                curr.push_back('0');
            }

            counter++;
            nums.push_back(curr);
        }

        string answer;
        for (int i = 0; i < nums.size(); i++)
        {
            answer = add(answer,nums[i]);
        }

        return answer;
    }
};