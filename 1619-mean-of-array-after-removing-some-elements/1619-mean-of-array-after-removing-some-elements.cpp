class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(begin(arr), end(arr));

        int index = arr.size() * 0.05;

        double sum = 0;
        double counter = 0;

        for (int i = index; i < arr.size() - index; i++) {
            sum += arr[i];
            counter++;
        }

        return sum / counter;
    }
};