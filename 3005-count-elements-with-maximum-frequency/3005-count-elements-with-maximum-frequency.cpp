class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(100, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]-1]++;
        }

        int biggest = freq[0];
        int counter = 1;

        for (int i = 1; i < 100; i++)
        {
            if (freq[i] > biggest)
            {
                biggest = freq[i];
                counter = 1;
            }
            else if (freq[i] == biggest)
            {
                counter++;
            }
        }
        
        return counter*biggest;
    }
};