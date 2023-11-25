class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        vector<int> prefix(nums.size()+1, 0);
        vector<int> suffix(nums.size()+1, 0);

        int i = 0;
        int j = nums.size();

        int prefSum = 0;
        int sufSum = 0;

        while (i < nums.size())
        {
            prefSum += nums[i];
            sufSum += nums[j-1];

            prefix[i+1] = prefSum;
            suffix[j-1] = sufSum;

            i++;
            j--;
        }

        vector<int> output(nums.size(), 0);


        for (i = 0; i < nums.size(); i++)
        {   
            output[i] = (i * nums[i]) - prefix[i] + suffix[i+1] - ((nums.size()-1-i) * nums[i]);
        }


        return output;
    }
};