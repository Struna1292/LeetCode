class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        
        int lowest = tasks[0][0] + tasks[0][1];

        for (int i = 0; i < tasks.size(); i++) {
            if (lowest > tasks[i][0] + tasks[i][1]) {
                lowest = tasks[i][0] + tasks[i][1]; 
            }
        }

        return lowest;
    }
};