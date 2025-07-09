class Solution {
public:
    void DFS(vector<vector<int>>& graph, int curr, int target, vector<int> currPath, vector<vector<int>>& allPaths) {
        currPath.push_back(curr);
        if (curr == target) {
            allPaths.push_back(currPath);
            return;
        }

        for (int i = 0; i < graph[curr].size(); i++) {
            DFS(graph, graph[curr][i], target, currPath, allPaths);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> output; 

        DFS(graph, 0, graph.size()-1, {}, output);

        return output;
    }
};