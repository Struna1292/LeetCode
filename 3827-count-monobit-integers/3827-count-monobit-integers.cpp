class Solution {
public:
    int countMonobit(int n) {
        int curr = 0;
        int counter = 0;

        while (curr <= n) {
            curr <<= 1;
            curr |= 1;

            counter++;
        }

        return counter;
    }
};