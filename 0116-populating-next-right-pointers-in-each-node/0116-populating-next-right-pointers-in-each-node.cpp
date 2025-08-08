/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if (root == nullptr) {
            return nullptr;
        } 

        queue<Node*> que;
        que.push(root);

        while (!que.empty()) {

            int count = que.size();
            while (count > 0) {
                Node* curr = que.front();
                que.pop();

                if (curr->left != nullptr) {
                    que.push(curr->left);
                }
                if (curr->right != nullptr) {
                    que.push(curr->right);
                }

                count--;

                if (count == 0) {
                    curr->next = nullptr;
                } 
                else {    
                    curr->next = que.front();
                }
            }
        }

        return root;
    }
};