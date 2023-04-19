class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        vector<vector<int>> groups;

        vector<pair<int,int>> pairs; 

        for (int i = 0; i < groupSizes.size(); i++)
        {
            pairs.push_back({groupSizes[i],i});
        }

        sort(begin(pairs), end(pairs));

        vector<int> curr;
        vector<int> empty;
        for (int i = 0; i < pairs.size(); i++)
        {
            curr.push_back(pairs[i].second);
            if (curr.size() == pairs[i].first)
            {
                groups.push_back(curr);
                curr = empty;
            }
        }

        return groups;
    }
};