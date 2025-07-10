// Definition for a Node.
/*
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }

        vector<vector<int>> adjList(101, vector<int>());
        vector<Node*> nodes(101, nullptr);

        vector<bool> seen(101, false);
        queue<Node*> q;
        q.push(node);
        seen[node->val] = true;
 
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            nodes[curr->val] = new Node(curr->val);

            for (int i = 0; i < curr->neighbors.size(); i++) {
                adjList[curr->val].push_back(curr->neighbors[i]->val);

                if (!seen[curr->neighbors[i]->val]) {
                    q.push(curr->neighbors[i]);
                    seen[curr->neighbors[i]->val] = true;
                }
            }
        }

        for (int i = 0; i < adjList.size(); i++) {
            for (int j = 0; j < adjList[i].size(); j++) {
                int connectionIdx = adjList[i][j];
                nodes[i]->neighbors.push_back(nodes[connectionIdx]);
            }
        }

        return nodes[node->val];
    }
};