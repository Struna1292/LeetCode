class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int arrLength = end(arr) - begin(arr);
        int times;
        int sumArr = 0;
        for (int i = 0; i < arrLength; i++)
        {
            times = ceil((i+1)*(arrLength-i)/2.0);
            sumArr += (arr[i] * times);
        }
        return sumArr;
    }
};