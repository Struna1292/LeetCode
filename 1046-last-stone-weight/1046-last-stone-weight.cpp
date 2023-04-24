class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(begin(stones), end(stones), greater<int>());
        int curr = 0;
        while (stones.size() > 1)
        {
            curr = stones[0] - stones[1];
            if (curr > 0)
            {
                stones.erase(begin(stones));
                stones[0] = curr;
                sort(begin(stones), end(stones), greater<int>());
            }
            else
            {
                stones.erase(begin(stones));
                stones.erase(begin(stones));
            }
        }
        if (stones.size() == 1)
        {
            return stones[0];
        }
        return 0;
    }
};