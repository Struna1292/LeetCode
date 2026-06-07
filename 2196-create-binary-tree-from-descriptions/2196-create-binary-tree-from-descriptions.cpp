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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int, TreeNode*> nodes;
        unordered_map<int, int> parents; 

        for (int i = 0; i < descriptions.size(); i++) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];

            if (!nodes.contains(parent)) {
                nodes[parent] = new TreeNode(parent);
            }
            if (!nodes.contains(child)) {
                nodes[child] = new TreeNode(child);
            }
            

            TreeNode* parentNode = nodes[parent];
            TreeNode* childNode = nodes[child];

            if (isLeft == 1) {
                parentNode->left = childNode;
            }
            else {
                parentNode->right = childNode;
            }

            parents[child]++;
        }

        for (auto itr = nodes.begin(); itr != nodes.end(); itr++) {
            int value = itr->first;
            if (parents[value] == 0) {
                return itr->second;
            }
        }

        return nullptr;
    }
};