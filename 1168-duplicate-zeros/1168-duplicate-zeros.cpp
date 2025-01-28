class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> arr2;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                arr2.push_back(0);
            }
            if (arr2.size() == arr.size())
            {
                break;
            }
            arr2.push_back(arr[i]);
            if (arr2.size() == arr.size())
            {
                break;
            }
        }

        arr = arr2;
    }
};