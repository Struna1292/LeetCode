class Solution {
public:
    bool isPrime(int n)
    {
        for (int i = 2; i < n; i++) 
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int binarySearch(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target || (mid > 0 && nums[mid] > target && nums[mid-1] < target) || (mid == 0 && nums[mid] > target))
            {
                return nums[mid];
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

    bool primeSubOperation(vector<int>& nums) {
        
        int biggest = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > biggest)
            {
                biggest = nums[i];
            }
        }

        vector<int> primes;
        for (int i = 2; i < biggest; i++)
        {
            if (isPrime(i))
            {
                primes.push_back(i);
            }
        }
        
        for (int i = nums.size()-2; i >= 0; i--)
        {
            if (nums[i] >= nums[i+1])
            {
                int diff = nums[i] - nums[i+1] + 1;

                int prime = binarySearch(primes, diff);

                if (prime == -1 || prime >= nums[i])
                {
                    return false;
                }
                else
                {
                    nums[i] -= prime;
                }

            }
        }

        return true;
    }
};