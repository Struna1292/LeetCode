class Solution {
public:
    int getWinner(vector<int>& arr, int k) {

        if (k >= arr.size())
        {
            k = arr.size()-1;
        }
        
        int wins = 0;
        int prevWinner = arr[0];
        int i = 1;
        int j = 0;
        vector<int> arr2(arr.size(), 0);

        while (true)
        {
            if (i < arr.size())
            {
                if (arr[i] < prevWinner)
                {
                    wins++;
                    arr2[j] = arr[i];
                }
                else
                {
                    wins = 1;
                    arr2[j] = prevWinner;
                    prevWinner = arr[i];
                }
                j++;
                i++;
            }
            else
            {
                arr = arr2;
                i = 0;
                j = 0;
            }

            if (wins == k)
            {
                return prevWinner;
            }
        }

        return -1;
    }
};