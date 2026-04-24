class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int currPos = 0;
        int emptyCounter = 0;
        for (int i = 0; i < moves.length(); i++) {
            if (moves[i] == '_') {
                emptyCounter++;
            }
            else if (moves[i] == 'L') {
                currPos--;
            }
            else if (moves[i] == 'R') {
                currPos++;
            }
        }

        return max(abs(currPos - emptyCounter), currPos + emptyCounter);
    }
};