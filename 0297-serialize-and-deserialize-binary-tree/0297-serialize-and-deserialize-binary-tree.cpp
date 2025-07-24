/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeDFS(TreeNode* curr, string& s) {
        if (curr == nullptr) {
            string n = "null,";
            for (int i = 0; i < n.length(); i++) {
                s.push_back(n[i]);
            }
            return;
        }

        string num = to_string(curr->val);
        for (int i = 0; i < num.length(); i++) {
            s.push_back(num[i]);
        }
        s.push_back(',');

        serializeDFS(curr->left, s);
        serializeDFS(curr->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;

        serializeDFS(root, s);

        cout << s << endl;
        return s;
    }

    void deserializeDFS(TreeNode* curr, string& data, int& index) {
        
        string leftChild;
        for (int i = index; i < data.length() && data[i] != ','; i++) {
            leftChild.push_back(data[i]);
            index++;
        }
        index++;

        if (leftChild == "null") {
            curr->left = nullptr;
        }
        else {
            curr->left = new TreeNode(stoi(leftChild));
            deserializeDFS(curr->left, data, index);
        }


        string rightChild;
        for (int i = index; i < data.length() && data[i] != ','; i++) {
            rightChild.push_back(data[i]);
            index++;
        }
        index++;

        if (rightChild == "null") {
            curr->right = nullptr;
        }
        else {
            curr->right = new TreeNode(stoi(rightChild));
            deserializeDFS(curr->right, data, index);
        }

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null,") {
            return nullptr;
        }

        string rootValue;
        int i = 0;
        for (; i < data.length() && data[i] != ','; i++) {
            rootValue.push_back(data[i]);
        }
        i++;

        TreeNode* root = new TreeNode(stoi(rootValue));

        deserializeDFS(root, data, i);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));