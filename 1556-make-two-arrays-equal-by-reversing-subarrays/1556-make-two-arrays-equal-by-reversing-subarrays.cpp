class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        sort(begin(target), end(target));
        sort(begin(arr), end(arr));

        for (int i = 0; i < target.size(); i++)
        {
            if (target[i] != arr[i])
            {
                return false;
            }
        }

        return true;
    }
};