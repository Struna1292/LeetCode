class Solution {
public:
    int maxCoins(vector<int>& piles) {

        sort(begin(piles), end(piles), greater<int>());

        int output = 0;

        int moves = piles.size()/3;

        for (int i = 1; i < piles.size()-moves; i+=2)
        {
            output += piles[i];
        }

        return output;
    }
};