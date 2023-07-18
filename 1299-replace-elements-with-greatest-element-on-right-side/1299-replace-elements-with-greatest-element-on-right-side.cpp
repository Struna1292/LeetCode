class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> output(n, 0);

        int biggest = -1;

        for (int i = n-1; i >= 0; i--)
        {
            output[i] = biggest;
            if (arr[i] > biggest)
            {
                biggest = arr[i];
            }
        }

        return output;
    }
};