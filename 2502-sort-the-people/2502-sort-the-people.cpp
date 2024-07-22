class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> people;

        for (int i = 0; i < names.size(); i++)
        {
            people.push_back({heights[i], names[i]});
        }

        sort(begin(people), end(people));

        vector<string> output;

        for (int i = people.size()-1; i >= 0; i--)
        {
            output.push_back(people[i].second);
        }

        return output;
    }
};