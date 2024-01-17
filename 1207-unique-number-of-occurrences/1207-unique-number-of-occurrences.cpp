class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(begin(arr),end(arr));

        vector<int> frequencies;

        int prev = arr[0];
        int counter = 1;

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] != prev)
            {
                frequencies.push_back(counter);
                prev = arr[i];
                counter = 1;
            }
            else
            {
                counter++;
            }
        }
        frequencies.push_back(counter);


        sort(begin(frequencies), end(frequencies));

        for (int i = 0; i < frequencies.size()-1; i++)
        {
            if (frequencies[i] == frequencies[i+1])
            {
                return false;
            }
        }

        return true;
    }
};