class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int firstScore = 0;
        bool firstIsActive = true;

        int secondScore = 0;
        bool secondIsActive = false;

        int counter = 5;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                swap(firstIsActive, secondIsActive);
            }
            if (i == counter) {
                swap(firstIsActive, secondIsActive);
                counter += 6;
            }

            if (firstIsActive) {
                firstScore += nums[i];
            }
            else {
                secondScore += nums[i];
            }
        }   

        return firstScore - secondScore;
    }
};