class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> bits(arr.size(), {0, 0});

        for (int i = 0; i < arr.size(); i++)
        {
            int curr = arr[i];
            bits[i].second = curr;

            int counter = 0;
            while (curr > 0)
            {
                if ((curr & 1) == 1)
                {
                    counter++;
                }
                curr >>= 1;
            }

            bits[i].first = counter;
        }

        sort(begin(bits), end(bits));

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = bits[i].second;
        }

        return arr;
    }
};