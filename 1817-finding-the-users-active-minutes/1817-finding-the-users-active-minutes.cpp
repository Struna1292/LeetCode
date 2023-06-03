class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        struct userUAM 
        {
            int id;
            vector<int> minutes;
        };

        vector<userUAM> users;

        for (int i = 0; i < logs.size(); i++)
        {
            int counter = 0;
            for (int j = 0; j < users.size(); j++)
            {
                if (users[j].id == logs[i][0])
                {
                    users[j].minutes.push_back(logs[i][1]);
                    break;
                }
                else
                {
                    counter++;
                }
            }

            if (counter == users.size())
            {
                users.push_back({logs[i][0], {logs[i][1]}});
            }
        }

        vector<int> output(k, 0);

        for (int i = 0; i < users.size(); i++)
        {
            sort(begin(users[i].minutes), end(users[i].minutes));
            users[i].minutes.erase(unique(begin(users[i].minutes), end(users[i].minutes)),end(users[i].minutes));
            output[users[i].minutes.size()-1]++;
        }

        return output;
    }
};