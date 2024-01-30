class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        sort(begin(arr), end(arr), greater<int>());

        int freq = 1;

        int prev = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == prev)
            {
                freq++;
            }
            else
            {
                if (prev == freq)
                {
                    return prev;
                }
                freq = 1;
                prev = arr[i];
            }
        }
        if (prev == freq)
        {
            return prev;
        }

        return -1;
    }
};