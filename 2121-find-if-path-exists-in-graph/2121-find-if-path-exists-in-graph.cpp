class Solution {
public:
    bool BFS(vector<vector<int>>& graph, int source, int target) {
        vector<bool> seen(graph.size(), false);

        queue<int> q;
        q.push(source);

        seen[source] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == target) {
                return true;
            }

            for (int i = 0; i < graph[curr].size(); i++) {
                if (!seen[graph[curr][i]]) {
                    q.push(graph[curr][i]);
                    seen[graph[curr][i]] = true;
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> graph(n); // adjacency List

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        return BFS(graph, source, destination);
    }
};