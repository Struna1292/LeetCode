class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {

        sort(begin(items1), end(items1));
        sort(begin(items2), end(items2));

        int j = 0;
        int length = end(items1) - begin(items1);
        for (int i = 0; i < items2.size(); i++)
        {
            while (j < length && items2[i][0] > items1[j][0])
            {
                j++;
            }
            if (j == length || items2[i][0] < items1[j][0])
            {
                items1.push_back({items2[i][0], items2[i][1]});
            }
            else if (items2[i][0] == items1[j][0])
            {
                items1[j][1] += items2[i][1];
                j++;
            }

        }

        sort(begin(items1), end(items1));

        return items1;
    }
};