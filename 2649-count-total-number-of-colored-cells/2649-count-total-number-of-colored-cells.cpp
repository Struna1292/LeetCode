class Solution {
public:
    long long coloredCells(int n) {
        
        //(n-1)*4+4 formula to calculate how much squares can be added

        long long curr = 1;

        for (int i = 1; i < n; i++)
        {
            curr += (i-1)*4+4;
        }

        return curr;
    }
};