class Graph {
public:
    struct edge {
        int to;
        int cost;
        edge(int t, int c) {
            to = t;
            cost = c;
        }
    };

    vector<vector<edge>> adjList;

    Graph(int n, vector<vector<int>>& edges) {
        
        adjList = vector<vector<edge>>(n);

        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edge(edges[i][1],edges[i][2]));
        }
    }
    
    void addEdge(vector<int> e) {
        adjList[e[0]].push_back(edge(e[1],e[2]));
    }
    
    struct comparator {
        bool operator()(edge a, edge b) {
            return a.cost > b.cost;
        }
    };

    int shortestPath(int node1, int node2) {

        vector<int> dists(adjList.size(), INT_MAX);
        priority_queue<edge, vector<edge>, comparator> pq;

        dists[node1] = 0;
        pq.push(edge(node1, 0));

        while (!pq.empty()) {
            edge currEdge = pq.top();
            pq.pop();

            int currCost = currEdge.cost;
            int currNode = currEdge.to;

            if (currCost > dists[currNode]) {
                continue;
            }

            for (int i = 0; i < adjList[currNode].size(); i++) {
                edge e = adjList[currNode][i];

                if (currCost + e.cost < dists[e.to]) {
                    dists[e.to] = currCost + e.cost;
                    pq.push(edge(e.to, dists[e.to]));
                }
            }
        }

        if (dists[node2] == INT_MAX) {
            return -1;
        }

        return dists[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */