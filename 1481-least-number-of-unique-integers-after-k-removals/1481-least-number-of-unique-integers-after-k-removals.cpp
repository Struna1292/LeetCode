class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        sort(begin(arr), end(arr));
        
        vector<pair<int,int>> freq; // frequency and number

        int prev = arr[0];
        int counter = 1;

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == prev)
            {
                counter++;
            }
            else
            {
                freq.push_back({counter, prev});
                counter = 1;
                prev = arr[i];
            }
        }
        freq.push_back({counter, prev});

        sort(begin(freq), end(freq));

        int i = 0;

        while (k > 0)
        {
            if (k >= freq[i].first)
            {
                k -= freq[i].first;
                i++;
            }
            else
            {
                break;
            }
        }

        return freq.size() - i;
    }
};