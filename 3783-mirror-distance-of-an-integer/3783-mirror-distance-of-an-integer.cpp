class Solution {
public:
    int mirrorDistance(int n) {
        int reversed = 0;
        int num = n;

        while (num != 0) {
            int digit = num % 10;          
            reversed = reversed * 10 + digit; 
            num /= 10;                    
        }

        return  abs(n - reversed);
    }
};