class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int counter = 0;
        int score = 0;
        for (int i = 0; i < events.size() && counter < 10; i++) {
            if (events[i].length() == 1) {
                char c = events[i][0];
                if (c >= '0' && c <= '6') {
                    score += c - '0';
                }
                else {
                    counter++;
                }
            }
            else {
                score++;
            }
        }

        return { score, counter };
    }   
};