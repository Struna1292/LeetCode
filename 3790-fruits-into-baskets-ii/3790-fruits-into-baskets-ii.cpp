class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int output = 0;

        for (int i = 0; i < fruits.size(); i++)
        {
            bool found = false;
            for (int j = 0; j < baskets.size(); j++)
            {
                if (fruits[i] <= baskets[j])
                {   
                    found = true;
                    baskets[j] = 0;
                    break;
                }
            }

            if (!found)
            {
                output++;
            }
        }

        return output;
    }
};