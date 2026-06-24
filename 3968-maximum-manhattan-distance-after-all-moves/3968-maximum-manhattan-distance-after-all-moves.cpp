class Solution {
public:
    int maxDistance(string moves) {
        int x = 0;
        int y = 0;
        int counter = 0;

        for (int i = 0; i < moves.length(); i++) {
            switch (moves[i]) {
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case '_':
                    counter++;
                    break;
            }
        }

        return abs(x) + abs(y) + counter;
    }
};