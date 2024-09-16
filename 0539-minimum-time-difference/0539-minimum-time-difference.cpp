class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        vector<vector<int>> times;

        for (string s : timePoints)
        {

            string first;
            first.push_back(s[0]);
            first.push_back(s[1]);

            vector<int> curr;
            curr.push_back(stoi(first));

            string second;
            second.push_back(s[3]);
            second.push_back(s[4]);

            curr.push_back(stoi(second));

            times.push_back(curr);
            times.push_back({curr[0]+24, curr[1]});
        }

        sort(begin(times), end(times));

        int output = 0;

        for (int i = 1; i < times.size(); i++)
        {
            int diff = ((times[i][0] * 60) + times[i][1]) - ((times[i-1][0] * 60) + times[i-1][1]);

            if (diff < output || i == 1)
            {
                output = diff;
            }
        }

        return output;
    }
};