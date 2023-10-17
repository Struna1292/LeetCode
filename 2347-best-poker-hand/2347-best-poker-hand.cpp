class Solution {
public:
    bool checkFlush(vector<char>& suits)
    {
        char color = suits[0];
        for (int i = 1; i < suits.size(); i++)
        {
            if (suits[i] != color)
                return false;
        }
        
        return true;
    }

    string bestHand(vector<int>& ranks, vector<char>& suits) {
        
        if (checkFlush(suits))
        {
            return "Flush";
        }

        sort(begin(ranks), end(ranks));

        int highest = 0;
        int counter = 1;
        int prev = ranks[0];

        for (int i = 1; i < ranks.size(); i++)
        {
            if (ranks[i] == prev)
            {
                counter++;
            }
            else
            {
                counter = 1;
            }
            prev = ranks[i];
            if (counter > highest)
            {
                highest = counter;
            }
        }

        if (highest >= 3)
        {
            return "Three of a Kind";
        }
        else if (highest == 2)
        {
            return "Pair";
        }

        return "High Card";
    }
};