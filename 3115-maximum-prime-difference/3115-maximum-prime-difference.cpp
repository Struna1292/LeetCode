class Solution {
public:
    int binarySearch(vector<pair<int,bool>>& verifiedNumbers, int target)
    {
        int left = 0;
        int right = verifiedNumbers.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (verifiedNumbers[mid].first == target)
            {
                if (verifiedNumbers[mid].second == true)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }

            if (verifiedNumbers[mid].first < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }

    int maximumPrimeDifference(vector<int>& nums) {

        int firstIndex = -1;
        int lastIndex = -1;

        vector<pair<int,bool>> verifiedNumbers;

        for (int i = 0; i < nums.size(); i++)
        {
            int check = binarySearch(verifiedNumbers, nums[i]);
            // -1 - not found, 0 - not prime, 1 - is prime 

            if (check == -1 && nums[i] != 1)
            {
                bool isPrime = true;
                for (int j = nums[i]-1; j >= 2; j--)
                {
                    if (nums[i] % j == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }

                verifiedNumbers.push_back({nums[i], isPrime});
                sort(begin(verifiedNumbers), end(verifiedNumbers));

                if (isPrime)
                {
                    if (firstIndex == -1)
                    {
                        firstIndex = i;
                    }
                    lastIndex = i;
                }
            }
            else if (check == 1)
            {
                lastIndex = i;
            }

        }

        return lastIndex - firstIndex;
    }
};