class Solution {
public:
    int minPairSum(vector<int>& nums) {

        vector<int> arr;
        int n = nums.size();
        arr.reserve(n/2);

        sort(begin(nums), end(nums));

        int i = 0;
        int j = n-1;
        while (i < j)
        {
            arr.emplace_back(nums[i] + nums[j]);
            i++;
            j--;
        }

        int biggest = arr[0];
        for (i = 1; i < n/2; i++)
        {   
            if (arr[i] > biggest)
            {
                biggest = arr[i];
            }
        }

        return biggest;
    }
};