class Solution {
public:

    vector<pair<int,int>> countOccurrences(vector<int>& nums)
    {
        vector<pair<int, int>> output;

        sort(begin(nums), end(nums));

        int prev = nums[0];
        int counter = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == prev)
            {
                counter++;
            }
            else
            {
                output.push_back({counter, prev});
                counter = 1;
            }
            prev = nums[i];
        }
        output.push_back({counter, prev});

        return output;
    }

    void bubbleSort(vector<pair<int,int>> &nums)
    {
        bool swapped = false;
        for (int i = 0; i < nums.size()-1; i++)
        {
            swapped = false;
            for (int j = 0; j < nums.size()-1-i; j++)
            {
                if (nums[j].first > nums[j+1].first)
                {
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
                else if (nums[j].first == nums[j+1].first)
                {
                    if (nums[j].second < nums[j+1].second)
                    {
                        swap(nums[j], nums[j+1]);
                        swapped = true;
                    }
                }
            }
        }
    }

    vector<int> frequencySort(vector<int>& nums) {

        vector<pair<int,int>> occurrences = countOccurrences(nums);

        bubbleSort(occurrences);

        vector<int> output;

        for (int i = 0; i < occurrences.size(); i++)
        {
            for (int j = 0; j < occurrences[i].first; j++)
            {
                output.push_back(occurrences[i].second);
            }
        }

        return output;
    }
};