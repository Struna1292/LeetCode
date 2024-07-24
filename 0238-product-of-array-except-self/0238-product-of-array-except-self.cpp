class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> prefix(nums.size(), 0);
        vector<int> suffix(nums.size(), 0);

        int i = 0;
        int j = nums.size()-1;

        int leftCurr = 1;
        int rightCurr = 1;

        while (i < nums.size())
        {
            leftCurr *= nums[i];
            rightCurr *= nums[j];

            prefix[i] = leftCurr;
            suffix[j] = rightCurr;

            i++;
            j--;
        }

        for (i = 0; i < prefix.size(); i++)
        {
            cout << prefix[i] << " ";
        }
        cout << endl;

        for (i = 0; i < suffix.size(); i++)
        {
            cout << suffix[i] << " ";
        }
        cout << endl;

        vector<int> output(nums.size(), 0);

        output[0] = suffix[1];
        output[output.size()-1] = prefix[prefix.size()-2];

        for (int i = 1; i < nums.size()-1; i++)
        {
            output[i] = prefix[i-1] * suffix[i+1];
        }

        return output;
    }
};