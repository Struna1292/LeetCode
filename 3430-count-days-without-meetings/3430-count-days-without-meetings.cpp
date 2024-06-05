class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(begin(meetings), end(meetings));

        vector<vector<int>> meetings2;

        meetings2.push_back({meetings[0][0], meetings[0][1]});

        for (int i = 1; i < meetings.size(); i++)
        {
            bool match = true;

            if (meetings2[meetings2.size()-1][0] <= meetings[i][0] && meetings2[meetings2.size()-1][1] >= meetings[i][1])
            {
                match = false;
            }
            else if (meetings2[meetings2.size()-1][0] <= meetings[i][0] && meetings2[meetings2.size()-1][1] >= meetings[i][0])
            {
                meetings2[meetings2.size()-1][1] = meetings[i][1];
                match = false;
            }
            

            if (match)
            {
                meetings2.push_back(meetings[i]);
            }
        }


        int prev = 1;

        int output = 0;

        for (int i = 0; i < meetings2.size(); i++)
        {
            if (prev != meetings2[i][0] && i != 0)
            {
                output += meetings2[i][0] - prev - 1;
            }
            else
            {
                output += meetings2[i][0] - prev;
            }
            prev = meetings2[i][1];
        }

        output += days - prev;

        return output;
    }
};