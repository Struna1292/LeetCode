class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> output;
        vector<pair<int,int>> occurences;
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            counter = 0;
            for (int j = 0; j < occurences.size(); j++)
            {
                if (occurences[j].first == nums[i])
                {
                    occurences[j].second++;
                    break;
                }
                else
                {
                    counter++;
                }
            }
            if (counter == occurences.size())
            {
                occurences.push_back({nums[i],1});
            }
        }

        counter = 0;
        vector<int> curr;
        vector<int> empty;
        while (counter < occurences.size())
        {
            counter = 0;
            for (int i = 0; i < occurences.size(); i++)
            {
                if (occurences[i].second == 0)
                {
                    counter++;
                }
                else
                {
                    occurences[i].second--;
                    curr.push_back(occurences[i].first);
                }
            }
            if (curr != empty)
            {
                output.push_back(curr);
                curr = empty;
            }
        }
        return output;
    }
};