class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        // from 1-9 there is 9 combinations
        // in 2 digits there is 8 combinations and so on

        int currIncrement = 1;
        string start = "0";
        vector<int> combinations;

        for (int i = 9; i > 0; i--) {
            int currValue = stoi(start);
            for (int j = 0; j < i; j++) {
                currValue += currIncrement;

                if (currValue >= low && currValue <= high) {
                    combinations.push_back(currValue);
                }
            }

            currIncrement *= 10;
            currIncrement++;

            // add to starting value last digit incremented by 1
            start.push_back(start[start.length()-1]+1);
        }

        return combinations;
    }
};