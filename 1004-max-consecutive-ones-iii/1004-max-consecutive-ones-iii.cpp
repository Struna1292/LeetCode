class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int counter = 0;
        int biggest = 0;
        int curr = 0;
        vector<int> zeros;
        int zerosCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                curr++;
            }
            else
            {
                zeros.push_back(i);
                if (counter < k)
                {
                    curr++;
                    counter++;
                }
                else
                {
                    curr = i - zeros[zerosCount];
                    zerosCount++;
                }
            }

            if (curr > biggest)
            {
                biggest = curr;
            }
        }

        return biggest;
    }
};