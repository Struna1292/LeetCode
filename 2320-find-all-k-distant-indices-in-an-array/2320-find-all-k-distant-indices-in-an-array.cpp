class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        vector<int> prefix(nums.size(), -1);
        int counter = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                counter = 0;
            }
            else if (counter != -1) {
                counter++;
            }

            prefix[i] = counter;
            cout << prefix[i] << " ";
        }

        vector<int> suffix(nums.size(), -1);
        counter = -1;
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] == key) {
                counter = 0;
            }
            else if (counter != -1) {
                counter++;
            }

            suffix[i] = counter;
        }

        vector<int> output;

        for (int i = 0; i < nums.size(); i++) {
            if ((prefix[i] != -1 && prefix[i] <= k) || (suffix[i] != -1 && suffix[i] <= k)) {
                output.push_back(i);
            }
        }

        return output;
    }
};