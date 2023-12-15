class Solution {
public:
    void helper(vector<string>& output, vector<pair<int,string>>& keyboard, string curr, int i, string& digits)
    {
        if (i < digits.length())
        {
            for (int j = 0; j < keyboard.size(); j++)
            {
                if (keyboard[j].first == digits[i] - '0')
                {
                    for (int k = 0; k < keyboard[j].second.length(); k++)
                    {
                        string c = curr;
                        c.push_back(keyboard[j].second[k]);
                        helper(output, keyboard, c, i+1, digits);
                    }
                    break;
                }
            }
        }
        else
        {
            output.push_back(curr);
            return;
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.length() == 0)
        {
            return {};
        }

        vector<pair<int,string>> keyboard = {
            {2, "abc"}, {3, "def"},
            {4, "ghi"}, {5, "jkl"}, {6, "mno"},
            {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
        };

        vector<string> output;

        helper(output, keyboard, "", 0, digits);

        return output;
    }
};