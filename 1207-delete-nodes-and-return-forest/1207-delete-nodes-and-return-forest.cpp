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
    bool binarySearch(vector<int> nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return true;
            }

            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }

    void inOrder(TreeNode* root, vector<int>& to_delete, bool& found, vector<TreeNode*>& currTrees)
    {
        if (root == nullptr || found)
        {
            return;
        }

        if (binarySearch(to_delete, root->val))
        {
            found = true;

            TreeNode* temp = root;

            if (temp->left != nullptr)
            {
                currTrees.push_back(temp->left);
            }

            if (temp->right != nullptr)
            {
                currTrees.push_back(temp->right);
            }

            currTrees[0] = nullptr;

            delete temp;

            return;
        }

        if (root->left != nullptr && binarySearch(to_delete, root->left->val))
        {
            found = true;

            TreeNode* temp = root->left;

            root->left = nullptr;

            if (temp->left != nullptr)
            {
                currTrees.push_back(temp->left);
            }

            if (temp->right != nullptr)
            {
                currTrees.push_back(temp->right);
            }

            root = nullptr;

            delete temp;

            return;
        }

        if (root->right != nullptr && binarySearch(to_delete, root->right->val))
        {
            found = true;

            TreeNode* temp = root->right;

            root->right = nullptr;
            
            if (temp->left != nullptr)
            {
                currTrees.push_back(temp->left);
            }

            if (temp->right != nullptr)
            {
                currTrees.push_back(temp->right);
            }

            delete temp;

            return;
        }

        inOrder(root->left, to_delete, found, currTrees);

        inOrder(root->right, to_delete, found, currTrees);
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        sort(begin(to_delete), end(to_delete));

        vector<TreeNode*> currTrees;
        currTrees.push_back(root);

        vector<TreeNode*> output;

        while (currTrees.size() > 0)
        {
            bool found = false;

            inOrder(currTrees[0], to_delete, found, currTrees);

            if (!found)
            {
                output.push_back(currTrees[0]);
                currTrees.erase(currTrees.begin());
            }
            else
            {
                if (currTrees[0] == nullptr)
                {
                    currTrees.erase(currTrees.begin());
                }
            }

        }


        return output;
    }   
};