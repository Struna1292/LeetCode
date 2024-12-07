class Solution {
public:
    int smallestNumber(int n) {
        
        int curr = 1;

        while (curr < n)
        {
            curr <<= 1;
            curr |= 1;
        }

        return curr;
    }
};