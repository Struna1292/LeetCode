class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        sort(begin(gifts), end(gifts), greater<int>());

        long long output = 0;
        for (int i = 0; i < k; i++)
        {
            gifts[0] = sqrt(gifts[0]);
            sort(begin(gifts), end(gifts), greater<int>());
        }
        
        for (int i = 0; i < gifts.size(); i++)
        {
            output += gifts[i];
        }

        return output;
    }
};