class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {

        if (k == weights.size() || k == 1)
        {
            return 0;
        }
        
        // find best split positions by creating vector of every pair and sorting

        vector<int> bestPairs;

        for (int i = 1; i < weights.size(); i++)
        {
            bestPairs.push_back(weights[i-1] + weights[i]);
        }

        sort(begin(bestPairs), end(bestPairs));

        long long minimum = weights[0] + weights[weights.size()-1]; // first and last element is core we cant get rid of them

        for (int i = 0; i < k-1; i++)
        {
            minimum += bestPairs[i];
        }

        long long maximum = weights[0] + weights[weights.size()-1];

        for (int i = bestPairs.size()-1; i > bestPairs.size()-1-k+1; i--)
        {
            maximum += bestPairs[i];
        }


        return maximum - minimum;
    }
};