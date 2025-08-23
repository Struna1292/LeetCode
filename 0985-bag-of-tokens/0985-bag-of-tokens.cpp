class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(begin(tokens), end(tokens));

        int i = 0;
        int j = tokens.size()-1;

        int score = 0;
        int bestScore = 0;

        while (i <= j) {
            if (tokens[i] <= power) {
                score++;
                power -= tokens[i];
                i++;

                if (score > bestScore) {
                    bestScore = score;
                }
            }
            else {
                if (score == 0) {
                    break;
                }

                score--;
                power += tokens[j];
                j--;
            }
        }

        return bestScore;
    }
};