class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq(begin(piles), end(piles));

        for (int i = 0; i < k; i++)
        {
            int num = pq.top() - floor(pq.top() / 2);
            pq.pop();
            pq.push(num);
        }

        int minSum = 0;
        while(!pq.empty())
        {
            minSum += pq.top();
            pq.pop();
        }

        return minSum;
    }
};