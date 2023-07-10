class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {

        if (arr.size() == k)
        {
            return arr;
        }
        
        sort(begin(arr), end(arr));

        int m = arr[(arr.size()-1)/2];

        int i = 0;
        int j = arr.size()-1;
        vector<int> output;
        while (i < j && output.size() < k)
        {
            if (abs(arr[i] - m) <= abs(arr[j] - m))
            {
                output.push_back(arr[j]);
                j--;
            }
            else
            {
                output.push_back(arr[i]);
                i++;
            }
        }

        return output;
    }
};