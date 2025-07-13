class Solution {
public:
    struct edge {
        int to;
        int start;
        int end;
        edge(int t, int s, int e) {
            to = t;
            start = s;
            end = e;
        }
    };

    struct comparator {
        bool operator()(edge a, edge b) {
            return a.start > b.start;
        }
    };

    int minTime(int n, vector<vector<int>>& edges) {
        
        // think about the edges as bridges that are available between start and end hours
        // iterate with dijkstra algorithm but notice its impossible to go to use edge when we are late
        // or our actual time is less than end then we look at start and if we need to wait for start

        vector<vector<edge>> adjList(n);

        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edge(edges[i][1], edges[i][2], edges[i][3]));
        }

        // dijkstra
        vector<int> dists(n, INT_MAX);
        priority_queue<edge, vector<edge>, comparator> pq; // min heap

        dists[0] = 0;
        pq.push(edge(0, 0, 0));

        while (!pq.empty()) {
            
            edge currEdge = pq.top();
            pq.pop();

            int currVertex = currEdge.to;
            int currTime = currEdge.start;

            if (currTime > dists[currVertex]) { // if we already found quicker way to this vertex 
                continue;
            }

            for (int i = 0; i < adjList[currVertex].size(); i++) {
                edge e = adjList[currVertex][i];
                if (currTime > e.end) { // too late to use edge
                    continue;
                }
                int nextTime = max(currTime, e.start) + 1; // if we came too early we wait, if we came later we go with our time
                // +1 because thats the cost of our action
                if (nextTime < dists[e.to]) { 
                    dists[e.to] = nextTime;
                    pq.push(edge(e.to, nextTime, 0)); // end time doesnt matter to heap edges
                }
            }
        } 

        
        return (dists[n-1] == INT_MAX) ? -1 : dists[n-1];
    }   
};