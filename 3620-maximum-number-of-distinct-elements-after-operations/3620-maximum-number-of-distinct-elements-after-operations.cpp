class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        multiset<int> ms;

        int minNumber = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            ms.insert(nums[i]);
            minNumber = min(minNumber, nums[i]);
        }

        ms.erase(ms.find(minNumber));

        int distinctCounter = 1;
        int curr = minNumber - k;

        while (!ms.empty()) {
            auto itr = ms.upper_bound(curr-k);

            if (itr == ms.end()) {
                break;
            }
            else if (curr+k+1 >= *itr) {
                distinctCounter++;
                ms.erase(itr);
            }

            curr++;
        }

        return distinctCounter;
    }
};