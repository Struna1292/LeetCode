class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {

        vector<vector<int>> output;

        sort(begin(items1), end(items1));
        sort(begin(items2), end(items2));

        int i = 0;
        int j = 0;
        while (i < items1.size() && j < items2.size())
        {
            if (items1[i][0] == items2[j][0])
            {
                output.push_back({items1[i][0], items1[i][1] + items2[j][1]});
                i++;
                j++;
            }
            else if (items1[i][0] > items2[j][0])
            {
                output.push_back({items2[j][0], items2[j][1]});
                j++;
            }
            else if (items1[i][0] < items2[j][0])
            {
                output.push_back({items1[i][0], items1[i][1]});
                i++;
            }
        }

        if (i == items1.size())
        {
            while (j < items2.size())
            {
                output.push_back({items2[j][0], items2[j][1]});
                j++;
            }
        }
        else
        {
            while (i < items1.size())
            {
                output.push_back({items1[i][0], items1[i][1]});
                i++;
            }
        }

        return output;
    }
};