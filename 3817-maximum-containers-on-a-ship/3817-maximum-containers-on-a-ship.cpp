class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        
        int contenerCount = n*n;
        int currWeight = contenerCount * w;

        while (currWeight > maxWeight)
        {
            contenerCount--;
            currWeight -= w;
        }

        return contenerCount;
    }
};