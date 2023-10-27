class Solution {
public:
    vector<int> minOperations(string boxes) {

        vector<int> output(boxes.length(), 0);

        int balls = 0;
        int moves = 0;

        for (int i = 0; i < boxes.length(); i++)
        {
            moves += balls;
            output[i] += moves;
            if (boxes[i] == '1')
                balls++;
        }

        balls = 0;
        moves = 0;

        for (int i = boxes.length()-1; i >= 0; i--)
        {
            moves += balls;
            output[i] += moves;
            if (boxes[i] == '1')
                balls++;
        }

        return output;
    }
};