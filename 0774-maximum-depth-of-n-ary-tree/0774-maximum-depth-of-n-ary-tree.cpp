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
    void inOrder(Node* root, int depth, int& output)
    {
        if (root == nullptr)
        {
            return;
        }

        if (depth > output)
        {
            output = depth;
        }
        for (int i = 0; i < root->children.size(); i++)
        {
            inOrder(root->children[i], depth+1, output);
        }
    }

    int maxDepth(Node* root) {
        
        int output = 0;

        inOrder(root, 1, output);

        return output;
    }
};