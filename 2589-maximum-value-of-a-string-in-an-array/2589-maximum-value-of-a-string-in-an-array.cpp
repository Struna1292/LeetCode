class Solution {
public:
    bool onlyDigits(string& s)
    {
        for (char c : s)
        {
            if (c < '0' || c > '9')
            {
                return false;
            }
        }
        return true;
    }

    int maximumValue(vector<string>& strs) {
        
        int output = 0;

        for (string s : strs)
        {
            int currValue = 0;
            if (onlyDigits(s))
            {
                currValue = stoi(s);
            }
            else
            {
                currValue = s.length();
            }

            if (currValue > output)
            {
                output = currValue;
            }
        }

        return output;
    }
};