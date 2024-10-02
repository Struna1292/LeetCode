class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        map<int,int> nums;

        for (int i = 0; i < arr.size(); i++)
        {
            nums.insert({arr[i], 0});
        }

        int counter = 1;

        for (auto itr = nums.begin(); itr != nums.end(); itr++)
        {
            itr->second = counter;
            counter++;
        }

        vector<int> output;

        for (int i = 0; i < arr.size(); i++)
        {
            output.push_back(nums[arr[i]]);
        }

        return output;
    }
};