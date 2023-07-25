class Solution {
public:
    int biggestIndex(vector<int>& nums)
    {
        int biggest = nums[0];
        int index = 0;
        for (int i = 1; i < 3; i++)
        {
            if (nums[i] > nums[index])
            {
                biggest = nums[i];
                index = i;
            }
        }
        return index;
    }

    int fidnAnotherBiggest(vector<int>& nums, int ignore)
    {
        int index = -1;
        int biggest = -1;
        for (int i = 0; i < 3; i++)
        {
            if (i != ignore && nums[i] > biggest) 
            {
                index = i;
                biggest = nums[i];
            }
        }
        return index;
    }

    string longestDiverseString(int a, int b, int c) {

        vector<int> nums = {a,b,c};

        string s;

        int ignore = -1;

        while (true)
        {
            int index = biggestIndex(nums);
            if (nums[index] == 0)
                break;

            if (index == ignore)
            {
                index = fidnAnotherBiggest(nums, ignore);
                if (nums[index] == 0)
                    break;
            }


            if (nums[index] >= 2 && (ignore == -1 || nums[ignore] <= nums[index]))
            {
                nums[index] -= 2;
                s.push_back(index + 'a');
                s.push_back(index + 'a');
            }
            else
            {
                nums[index]--;
                s.push_back(index + 'a');
            }
            ignore = index;
            
        }

        return s;
    }
};