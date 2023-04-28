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

    void traversal(Node* root ,vector<int> &output)
    {
        if (root == NULL)
        {
            return;
        }

        output.push_back(root->val);

        for (int i = 0; i < root->children.size(); i++)
        {
            traversal(root->children[i], output);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> output;
        traversal(root, output);
        return output;
    }
};