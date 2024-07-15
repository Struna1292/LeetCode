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

    int binarySearch(vector<vector<int>>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid][0] == target)
            {
                return mid;
            }
            
            if (nums[mid][0] > target)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }

        return -1;
    }

    void helper(TreeNode* root, vector<vector<int>>& descriptions)
    {
        int index = binarySearch(descriptions, root->val);

        if (index == -1)
        {
            return;
        }

        int leftVal = -1;
        int rightVal = -1;

        if (descriptions[index][2] == 1)
        {
            leftVal = descriptions[index][1];

            if (index > 0)
            {
                if (descriptions[index-1][0] == descriptions[index][0])
                {
                    rightVal = descriptions[index-1][1];
                }
            }
            if (index < descriptions.size()-1)
            {
                if (descriptions[index+1][0] == descriptions[index][0])
                {
                    rightVal = descriptions[index+1][1];
                }
            }
        }
        else
        {
            rightVal = descriptions[index][1];

            if (index > 0)
            {
                if (descriptions[index-1][0] == descriptions[index][0])
                {
                    leftVal = descriptions[index-1][1];
                }
            }
            if (index < descriptions.size()-1)
            {
                if (descriptions[index+1][0] == descriptions[index][0])
                {
                    leftVal = descriptions[index+1][1];
                }
            }
        }


        if (leftVal != -1)
        {
            root->left = new TreeNode;
            root->left->val = leftVal;
            helper(root->left, descriptions);
        }

        if (rightVal != -1)
        {
            root->right = new TreeNode;
            root->right->val = rightVal;
            helper(root->right, descriptions);
        }
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        sort(begin(descriptions), end(descriptions));

        map<int,int> mp;
        
        for (int i = 0; i < descriptions.size(); i++)
        {
            mp[descriptions[i][0]]++;
            mp[descriptions[i][1]] += 4;
        }

        map<int,int>::iterator itr;

        int root = 0;

        for (itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second <= 2)
            {
                root = itr->first;
                break;
            }
        }

        TreeNode* output = new TreeNode;
        output->val = root;

        helper(output, descriptions);

        return output;
    }
};