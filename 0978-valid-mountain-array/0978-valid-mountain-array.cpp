class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if (arr.size() < 3)
        {
            return false;
        }

        bool peak = false;
        bool inc = false;

        for (int i = 1; i < arr.size(); i++)
        {
            if (peak)
            {
                if (arr[i-1] <= arr[i])
                {
                    return false;
                }
            }
            else
            {
                if (arr[i-1] == arr[i])
                {
                    return false;
                }
                else if (arr[i-1] > arr[i])
                {
                    peak = true;
                }
                else
                {
                    inc = true;
                }
            }
        }

        return peak && inc;
    }
};