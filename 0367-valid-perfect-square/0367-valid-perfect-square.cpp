class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = sqrt(num);

        int check = s * s;

        if (check == num)
        {
            return true;
        }
        return false;
    }
};