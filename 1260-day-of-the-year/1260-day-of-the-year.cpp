class Solution {
public:
    int dayOfYear(string date) {
        string year;
        for (int i = 0; i < 4; i++)
        {
            year.push_back(date[i]);
        }

        string month;
        for (int i = 5; i < 7; i++)
        {
            month.push_back(date[i]);
        }

        string day;
        for (int i = 8; i < 11; i++)
        {
            day.push_back(date[i]);
        }

        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // amount of days in a month

        // check leap year
        if ((stoi(year) % 4 == 0 && stoi(year) % 100 != 0) || stoi(year) % 400 == 0)
        {
            days[1]++;
        }
        
        int totalDays = stoi(day);

        for (int i = 1; i < stoi(month); i++)
        {
            totalDays += days[i-1];
        }

        return totalDays;
    }
};