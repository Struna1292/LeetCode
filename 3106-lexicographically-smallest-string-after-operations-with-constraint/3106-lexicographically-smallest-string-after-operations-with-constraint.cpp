class Solution {
public:
    int distanceToSmallestChar(char c, int k) {
        int distance = c - 'a';
        if (26 - distance < distance) {
            distance -= 26;
        }

        if (k < abs(distance)) {
            distance = k;
        }

        distance *= -1;   
        return distance;
    }

    string getSmallestString(string s, int k) {

        for (int i = 0; i < s.length() && k > 0; i++) {
            int dist  = distanceToSmallestChar(s[i], k);
            k -= abs(dist);

            s[i] = (s[i] + dist - 'a') % 26 + 'a';
        }
        
        return s;
    }
};