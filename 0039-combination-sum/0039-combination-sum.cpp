class Solution {
public:
    void helper(int i, vector<int>& candidates, vector<int> currNums, int currSum, int target, vector<vector<int>>& output, int possible)
    {
        if (possible != 0)
        {
            currNums.push_back(possible);
        }

        if (currSum == target)
        {
            output.push_back(currNums);
            return;
        }

        for (i; i < candidates.size(); i++)
        {
            if (currSum + candidates[i] <= target)
            {
                helper(i, candidates, currNums, currSum+candidates[i], target, output, candidates[i]);
            }
            else
            {
                break;
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));

        vector<vector<int>> output;

        helper(0, candidates, vector<int>(), 0, target, output, 0);

        return output;
    }
};