class Solution {
public:
    // represents if station has power and to which circuit is connected to
    struct Station {
        int circuitId = -1;
        bool isPowered = true;

        Station(bool isP, int id) {
            isPowered = isP;
            circuitId = id;
        }
        Station() {
            circuitId = -1;
            isPowered = true;
        }
    };

    void DFS(int currStation, int& currCircuit, vector<vector<int>>& adjList, unordered_map<int, Station>& stations, unordered_map<int, priority_queue<int, vector<int>, greater<int>>>& circuits) {

        // if we enter station that is already in circuit and our currCircuit is empty then return
        if (stations[currStation].circuitId != -1 && circuits[currCircuit].empty()) {
            return;
        }

        // if we encounter different circuit erase old one and move it to new
        int prevCircuit = stations[currStation].circuitId;

        if (prevCircuit != currCircuit && prevCircuit != -1) {
            // check which one is smaller and move to other
            if (circuits[prevCircuit].size() < circuits[currCircuit].size()) {
                while (!circuits[prevCircuit].empty()) {
                    int curr = circuits[prevCircuit].top();
                    circuits[prevCircuit].pop();

                    stations[curr].circuitId = currCircuit;
                    circuits[currCircuit].push(curr);
                }
            }
            else {
                while (!circuits[currCircuit].empty()) {
                    int curr = circuits[currCircuit].top();
                    circuits[currCircuit].pop();

                    stations[curr].circuitId = prevCircuit;
                    circuits[prevCircuit].push(curr);

                }
                currCircuit = prevCircuit;
            }

            return;
        }
        else if (prevCircuit == currCircuit) {
            return;

        }        

        stations[currStation].circuitId = currCircuit;
        circuits[currCircuit].push(currStation);

        for (int i = 0; i < adjList[currStation].size(); i++) {
            DFS(adjList[currStation][i], currCircuit, adjList, stations, circuits);
        }
    }  

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        // key is station id value
        unordered_map<int, Station> stations;

        // key is circuit id value is min heap that contains stations in this circuit
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> circuits;

        // graph adjacency list
        vector<vector<int>> adjList(c, vector<int>());


        for (int i = 0; i < connections.size(); i++) {
            adjList[connections[i][0] - 1].push_back(connections[i][1] - 1);
            adjList[connections[i][1] - 1].push_back(connections[i][0] - 1);
        }

        int currCircuitId = 1;
        for (int i = 0; i < adjList.size(); i++) {
            DFS(i, currCircuitId, adjList, stations, circuits);
            currCircuitId++;
        }

        vector<int> output;

        for (int i = 0; i < queries.size(); i++) {

            int curr = queries[i][1] - 1;
            int circuit = stations[curr].circuitId;

            // maintenance check
            if (queries[i][0] == 1) {
                if (stations[curr].isPowered) {

                    output.push_back(curr + 1);

                }
                else {
                    int currBest = -1;

                    while (!circuits[circuit].empty()) {

                        int station = circuits[circuit].top();

                        if (stations[station].isPowered) {
                            currBest = station + 1;
                            break;
                        }
                        circuits[circuit].pop();
                    }
                    output.push_back(currBest);
                }
            }

            // station goes off
            else {
                stations[curr].isPowered = false;
            }
        }

        return output;
    }
};