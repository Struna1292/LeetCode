class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (mid+1 < nums.size() && nums[mid] < target && nums[mid+1] > target)
            {
                return mid+1;
            }

            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        vector<int> start1(flowers.size(), 0);
        vector<int> end1(flowers.size(), 0);

        for (int i = 0; i < flowers.size(); i++)
        {
            start1[i] = flowers[i][0];
            end1[i] = flowers[i][1];
        }

        sort(begin(start1), end(start1));
        sort(begin(end1), end(end1));

        vector<int> output(people.size(), 0);

        for (int i = 0; i < people.size(); i++)
        {
            output[i] = (upper_bound(begin(start1), end(start1), people[i]) - start1.begin()) - (lower_bound(begin(end1), end(end1), people[i]) - end1.begin());
        }

        return output;
    }
};