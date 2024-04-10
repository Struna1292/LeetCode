class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(begin(deck), end(deck));

        queue<int> q;

        for (int i = deck.size()-1; i >= 0; i--)
        {
            if (!q.empty())
            {   
                q.push(q.front());
                q.pop();
            }
            q.push(deck[i]);
        }

        vector<int> output(deck.size(), 0);

        int i = deck.size()-1;

        while (!q.empty())
        {
            output[i] = q.front();
            q.pop();
            i--;
        }

        return output;
    }
};