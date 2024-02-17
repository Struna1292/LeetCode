class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        
        sort(begin(seats), end(seats));

        sort(begin(students), end(students));

        int output = 0;

        for (int i = 0; i < students.size(); i++)
        {
            output += abs(seats[i] - students[i]);
        }

        return output;
    }
};