class Solution {
public:
    struct edge {
        int to;
        int cost;
        edge(int t, int c) {
            to = t;
            cost = c;
        }
    };

    int minScore(int n, vector<vector<int>>& roads) {
        n++;
        vector<vector<edge>> adjList(n);

        for (int i = 0; i < roads.size(); i++) {
            adjList[roads[i][0]].push_back(edge(roads[i][1], roads[i][2]));
            adjList[roads[i][1]].push_back(edge(roads[i][0], roads[i][2]));
        }
        
        int start = 1;
        int end = n-1;

        vector<bool> seen(n, false);

        queue<edge> q;
        q.push(edge(start, 0));

        int lowest = 0;

        while (!q.empty()) {

            edge currEdge = q.front();
            q.pop();

            int curr = currEdge.to;
            int currCost = currEdge.cost;
            seen[curr] = true;

            if (lowest == 0 || lowest > currCost) {
                lowest = currCost;
            }

            for (int i = 0; i < adjList[curr].size(); i++) {
                edge e = adjList[curr][i];

                if (lowest == 0 || lowest > e.cost) {
                    lowest = e.cost;
                }

                if (seen[e.to]) {
                    continue;
                }

                q.push(e);
            }
        }

        return lowest;
    }
};