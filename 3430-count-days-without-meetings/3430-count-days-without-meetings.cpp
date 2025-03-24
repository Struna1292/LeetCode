class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(begin(meetings), end(meetings));

        vector<vector<int>> merged{{meetings[0][0], meetings[0][1]}};

        for (int i = 1; i < meetings.size(); i++)
        {
            int start = merged[merged.size()-1][0];
            int end = merged[merged.size()-1][1];

            if (start == meetings[i][0] && end == meetings[i][1])
            {
                continue;
            }
            else if (start == meetings[i][0] && end < meetings[i][1])
            {
                merged[merged.size()-1][1] = meetings[i][1];
            }
            else if (end >= meetings[i][0] || end+1 == meetings[i][0])
            {
                if (end < meetings[i][1])
                {
                    merged[merged.size()-1][1] = meetings[i][1];
                }
            }
            else if (end >= days)
            {
                merged[merged.size()-1][1] = days;
                break;
            }
            else if (meetings[i][0] > days)
            {
                break;
            }
            else
            {
                merged.push_back(meetings[i]);
            }
        }

        int output = days;

        for (int i = 0; i < merged.size(); i++)
        {
            output -= (merged[i][1] - merged[i][0])+1;
        }

        return output;
    }
};