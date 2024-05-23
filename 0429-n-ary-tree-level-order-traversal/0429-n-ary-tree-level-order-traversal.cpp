/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void inOrder(Node* root, int depth, vector<vector<int>>& output)
    {
        if (output.size() < depth+1)
        {
            output.push_back({});
        }
        output[depth].push_back(root->val);

        if (root->children.size() >= 1)
        {
            for (int i = 0; i < root->children.size(); i++)
            {
                inOrder(root->children[i], depth+1, output);
            }
        }
        else
        {
            return;
        }
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> output;

        if (root != nullptr)
        {
            inOrder(root, 0, output);
        }

        return output;
    }
};