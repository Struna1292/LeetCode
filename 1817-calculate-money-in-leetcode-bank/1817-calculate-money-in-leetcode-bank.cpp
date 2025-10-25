class Solution {
public:
    int totalMoney(int n) {
        
        int totalWeeks = n / 7;
        int leftDays = n % 7;

        int output = totalWeeks * 28;

        for (int i = 1; i < totalWeeks; i++) {
            output += (7*i);
        }

        for (int i = 0; i < leftDays; i++) {
            output += i+1+totalWeeks;
        }

        return output;
    }
};