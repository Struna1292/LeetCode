class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(begin(piles), end(piles));

        int coins = 0;
        int i = 0;
        int j = piles.size()-1;
        while (i < j)
        {
            i++;
            j--;
            coins += piles[j];
            j--;
        }
        return coins;
    }
};