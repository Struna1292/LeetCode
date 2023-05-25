class Solution {
public:

    int convertToInt(string& s)
    {
        string num;
        for (int i = 0; i < s.length(); i++)
        {
            num.append(to_string(s[i] - 'a'));
        }

        return stoi(num);
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {

        int num1 = convertToInt(firstWord);

        int num2 = convertToInt(secondWord);

        int target = convertToInt(targetWord);

        if (num1+num2 == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};