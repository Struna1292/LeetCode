class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        sort(begin(candyType), end(candyType));

        int maximum = candyType.size();

        candyType.erase(unique(begin(candyType), end(candyType)), end(candyType));

        if (candyType.size() < (maximum / 2))
        {
            return candyType.size();
        }

        return maximum / 2;
    }
};