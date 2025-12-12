class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string output;

        while (sum > 0) {
            if (sum >= 9) {
                sum -= 9;
                output.push_back('9');
            }
            else {
                output.push_back(sum + '0');
                sum = 0;
            }
        }

        if (output.length() > num) {
            return "";
        }

        while (output.length() < num) {
            output.push_back('0');
        }

        return output;
    }
};