class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        sort(begin(pick), end(pick));

        map<int, map<int, int>> players; // first int is index of a player then map is color of ball and count

        for (int i = 0; i < pick.size(); i++)
        {
            players[pick[i][0]][pick[i][1]]++;
        }

        map<int, map<int, int>>::iterator itr;

        int winners = 0;
        for (itr = players.begin(); itr != players.end(); itr++)
        {
            map<int, int>::iterator i;
            for (i = itr->second.begin(); i != itr->second.end(); i++)
            {
                if (i->second > itr->first)
                {
                    winners++;
                    break;
                }
            }
        }

        return winners;
    }
};