class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<bool> visited(rooms.size(), false);

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (visited[curr]) {
                continue;
            }

            visited[curr] = true;

            for (int i = 0; i < rooms[curr].size(); i++) {
                int edge = rooms[curr][i];

                if (!visited[edge]) {
                    q.push(edge);
                }
            }
        }

        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};