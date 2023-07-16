/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* helper(Node* head)
    {
        Node* curr = head;
        Node* temp1 = nullptr;
        while (curr != NULL)
        {
            if (curr->child != NULL)
            {
                Node* temp = curr->next;
                curr->next = curr->child;
                curr->child = NULL;
                curr->next->prev = curr;
                curr = curr->next;
                Node* end = helper(curr);
                end->next = temp;
                if (temp != NULL)
                {
                    temp->prev = end;
                    curr = temp;
                    temp = temp->prev;
                }

            }
            temp1 = curr;
            curr = curr->next;
        }

        return temp1;
    }

    Node* flatten(Node* head) {
        
        Node* curr = head;

        helper(head);

        return head;
    }
};