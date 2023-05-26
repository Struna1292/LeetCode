class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> output;
        sort(begin(potions), end(potions));
        for (int i = 0; i < spells.size(); i++)
        {
            int counter = 0;
            double num = ceil((double)success / (double)spells[i]);
            if (potions[0] >= num)
            {
                counter += potions.size();
            }
            else if (potions[potions.size()-1] >= num)
            {
                auto index = lower_bound(begin(potions), end(potions), num);
                counter = potions.size() - (index - begin(potions));
            }
            output.push_back(counter);
        }
        return output;
    }
};