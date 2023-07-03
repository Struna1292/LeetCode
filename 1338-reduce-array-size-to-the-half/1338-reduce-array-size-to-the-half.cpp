class Solution {
public:
    int minSetSize(vector<int>& arr) {

        int n = arr.size();

        sort(begin(arr), end(arr));
        
        vector<pair<int, int>> freq;

        int counter = 1;
        int prev = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (arr[i] != prev)
            {
                freq.push_back({counter, prev});
                counter = 1;
                prev = arr[i];
            }
            else
            {
                counter++;
            }
        }
        freq.push_back({counter, prev});

        sort(begin(freq), end(freq));

        int half = n / 2;
        int sum = 0;
        int nums = 0;
        for (int i = freq.size()-1; i >= 0; i--)
        {
            sum += freq[i].first;
            nums++;
            if (sum >= half)
            {
                break;
            }
        }
        
        return nums;
    }
};