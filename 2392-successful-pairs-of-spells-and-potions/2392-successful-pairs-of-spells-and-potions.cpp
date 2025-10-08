class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(begin(potions), end(potions));
        vector<int> output(spells.size(), 0);

        for (int i = 0; i < spells.size(); i++) {
            if (spells[i] >= success) {
                output[i] = potions.size();
                continue;
            }

            long long curr = success / spells[i];
            int remainder = success % spells[i];

            if (remainder == 0) {
                curr--;
            }

            auto found = upper_bound(potions.begin(), potions.end(), curr);
            output[i] = potions.end() - found;
        }

        return output;
    }
};