class Solution {
public:
    string decimalStringToBinary(string decimal)
    {
        int num = stoi(decimal);

        string curr = bitset<32>(num). to_string();

        int i = 0;

        while (i < curr.length() && curr[i] == '0')
        {
            i++;
        }

        string output;

        while (i < curr.length())
        {
            output.push_back(curr[i]);
            i++;
        }

        if (output.length() < 1)
        {
            return "0";
        }

        return output;
    }

    string convertDateToBinary(string date) {
        
        string year;
        string month;
        string day;

        for (int i = 0; i < 4; i++)
        {
            year.push_back(date[i]);
        }

        for (int i = 5; i < 7; i++)
        {
            month.push_back(date[i]);
        }

        for (int i = 8; i < 10; i++)
        {
            day.push_back(date[i]);
        }

        return decimalStringToBinary(year) + "-" + decimalStringToBinary(month) + "-" + decimalStringToBinary(day);
    }
};