class Solution {
public:
    struct Item {
        int normal;
        int reversed;
        Item(int n, int r) {
            normal = n;
            reversed = r;
        }
    };

    struct Comparator {
        bool operator()(Item& a, Item& b) {
            if (a.reversed == b.reversed) {
                return a.normal < b.normal;
            }

            return a.reversed < b.reversed;
        }
    };

    vector<int> sortByReflection(vector<int>& nums) {

        vector<Item> output;
        
        for (int i = 0; i < nums.size(); i++) {
            int reversed = 0;
            int curr = nums[i];

            while (curr > 0) {
                reversed <<= 1;

                if ((curr & 1) == 1) {
                    reversed |= 1;
                }

                curr >>= 1;
            }

            output.push_back(Item(nums[i], reversed));
        }

        sort(begin(output), end(output), Comparator());

        for (int i = 0; i < output.size(); i++) {
            nums[i] = output[i].normal;
        }

        return nums;
    }
};