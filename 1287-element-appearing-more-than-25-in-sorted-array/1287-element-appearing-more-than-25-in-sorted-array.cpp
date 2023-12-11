class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int counter = 1;
        int prev = 1;
        int limit = arr.size()/4;

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == prev)
            {
                counter++;
            }
            else
            {
                counter = 1;
                prev = arr[i];
            }

            if (counter > limit)
            {
                return arr[i];
            }
        }

        return arr[0];
    }
};