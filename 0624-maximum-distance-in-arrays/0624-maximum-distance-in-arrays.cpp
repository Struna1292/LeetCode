class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        pair<int,int> min1 = {arrays[0][0], 0}; // value and index
        pair<int,int> min2;
        if (arrays[1][0] < min1.first)
        {
            min2 = min1;
            min1 = {arrays[1][0], 1};
        }
        else
        {
            min2 = {arrays[1][0], 1};
        }

        pair<int,int> max1 = {arrays[0][arrays[0].size()-1], 0};
        pair<int,int> max2;
        if (arrays[1][arrays[1].size()-1] > max1.first)
        {
            max2 = max1;
            max1 = {arrays[1][arrays[1].size()-1], 1};
        }
        else
        {
            max2 = {arrays[1][arrays[1].size()-1], 1};
        }


        for (int i = 2; i < arrays.size(); i++)
        {
            if (arrays[i][0] <= min1.first)
            {
                min2 = min1;
                min1.first = arrays[i][0];
                min1.second = i;
            }
            else if (arrays[i][0] < min2.first)
            {
                min2.first = arrays[i][0];
                min2.second = i;
            }

            if (arrays[i][arrays[i].size()-1] >= max1.first)
            {
                max2 = max1;
                max1.first = arrays[i][arrays[i].size()-1];
                max1.second = i;
            }
            else if (arrays[i][arrays[i].size()-1] > max2.first)
            {
                max2.first = arrays[i][arrays[i].size()-1];
                max2.second = i;
            }
        }

        if (min1.second != max1.second)
        {
            return max1.first - min1.first;
        }
        else
        {
            if (max1.first - min2.first > max2.first - min1.first)
            {
                return max1.first - min2.first;
            }
            else
            {
                return max2.first - min1.first;
            }
        }

        return 0;
    }
};