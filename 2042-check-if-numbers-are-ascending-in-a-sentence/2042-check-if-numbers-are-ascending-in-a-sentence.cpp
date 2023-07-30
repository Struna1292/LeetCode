class Solution {
public:
    bool areNumbersAscending(string s) {

        int prev = -1;
        string num;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num.push_back(s[i]);
            }
            else
            {
                if (num != "")
                {
                    int curr = stoi(num);
                    if (prev != -1 && curr <= prev)
                    {
                        return false;
                    }
                    else
                    {
                        prev = curr;
                        num = "";
                    }
                }
            }
        }

        if (num != "")
        {
            int curr = stoi(num);
            if (prev != -1 && curr <= prev)
            {
                return false;
            }
        }

        return true;
    }
};