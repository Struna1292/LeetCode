/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* find(TreeNode* curr, int& val, TreeNode* currPrev, TreeNode*& prev) {
        if (curr == nullptr) {
            return nullptr;
        }

        if (val == curr->val) {
            prev = currPrev;
            return curr;
        }

        if (val < curr->val) {
            return find(curr->left, val, curr, prev);
        }
        return find(curr->right, val, curr, prev);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* curr = find(root, key, nullptr, parent);

        if (curr == nullptr) { // value to delete not found
            return root;
        }

        if (curr->left == nullptr && curr->right == nullptr) { // node without childs
            if (curr == root) {
                root = nullptr;
            } else {
                // adjust parent connections
                if (parent->left == curr) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            }
        } else if (curr->left == nullptr) { // left child is empty
            if (curr == root) {
                root = curr->right;
            } else {
                // adjust parent connections
                if (parent->left == curr) {
                    parent->left = curr->right;
                } else {
                    parent->right = curr->right;
                }
            }
        } else if (curr->right == nullptr) { // right child is empty
            if (curr == root) {
                root = curr->left;
            } else {
                // adjust parent connections
                if (parent->left == curr) {
                    parent->left = curr->left;
                } else {
                    parent->right = curr->left;
                }
            }
        } else { // node to remove has both childs
            // first find the node to replace 
            // search for smallest node to the right of removal node (greatest to the left would work too)
            TreeNode* temp = curr->right;
            TreeNode* tempParent = nullptr;
            while (temp->left != nullptr) {
                tempParent = temp;
                temp = temp->left;
            }


            if (tempParent != nullptr) { // redirect connection from smallest parent to its right subtree
                tempParent->left = temp->right; // if there is no right subtree it will be nullptr
            }
            temp->left = curr->left; // connect left of replacing node to left of the removal node

            // connect right of replacing node to the right of removal if it exists
            if (curr->right != temp) {
                temp->right = curr->right;
            }

            if (curr == root) {
                root = temp;
            } else {
                if (parent->left == curr) {
                    parent->left = temp;
                } else {
                    parent->right = temp;
                }
            }
        }

        delete curr;

        return root;
    }
};