class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));

        long long currMass = mass;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > currMass) {
                return false;
            }
            else {
                currMass += asteroids[i];
            }
        }

        return true;
    }
};