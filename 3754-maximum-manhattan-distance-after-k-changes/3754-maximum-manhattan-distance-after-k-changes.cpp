class Solution {
public:
    int maxDistance(string s, int k) {
        
        int currX = 0;
        int currY = 0;
        int furthest = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == 'N') {
                currY++;
            } else if (c == 'S') {
                currY--;
            } else if (c == 'E') {
                currX++;
            } else {
                currX--;
            }

            int currDistance = abs(currX) + abs(currY);
            if (2*k < i+1-currDistance) {
                currDistance += 2*k;
            } else {
                currDistance += i+1-currDistance;
            }

            if (furthest < currDistance) {
                furthest = currDistance;
            }
        }

        return furthest;
    }
};