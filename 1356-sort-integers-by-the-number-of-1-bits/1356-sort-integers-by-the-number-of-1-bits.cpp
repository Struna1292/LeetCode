class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        vector<pair<int,int>> nums; // first is number of bits second is number

        for (int i = 0; i < arr.size(); i++)
        {
            int num = arr[i];

            int counter = 0;
            while (num != 0)
            {
                counter += (num & 1);
                num >>= 1;
            }

            nums.push_back({counter, arr[i]});
        }

        sort(begin(nums), end(nums));

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = nums[i].second;
        }

        return arr;
    }
};