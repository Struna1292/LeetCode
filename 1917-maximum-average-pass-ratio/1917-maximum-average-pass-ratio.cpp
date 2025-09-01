class Solution {
public:

    struct comparator {
        bool operator()(const vector<double>& a, const vector<double>& b) const {
            return a[0] < b[0];
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // max heap stores possible gains
        priority_queue<vector<double>, vector<vector<double>>, comparator> pq;
 
        double sum = 0;

        for (int i = 0; i < classes.size(); i++) {
            // classes where everyone passed
            if (classes[i][0] == classes[i][1]) {
                sum++;
                continue;
            }
            double pass = static_cast<double>(classes[i][0]);
            double total = static_cast<double>(classes[i][1]);
            double avg = pass / total;

            sum += avg;

            double possiblePass = pass + 1;
            double possibleTotal = total + 1;
            double possibleGain = (possiblePass / possibleTotal) - avg;

            pq.push({ possibleGain, possiblePass, possibleTotal });
        }

        while (extraStudents > 0 && !pq.empty()) {
            
            vector<double> curr = pq.top();
            pq.pop();
            sum += curr[0];

            double prevAvg = curr[1] / curr[2];
            double possiblePass = curr[1] + 1;
            double possibleTotal = curr[2] + 1;
            double possibleGain = (possiblePass / possibleTotal) - prevAvg;            

            pq.push({ possibleGain, possiblePass, possibleTotal });
            extraStudents--;
        }

        return sum / static_cast<double>(classes.size());
    }
};