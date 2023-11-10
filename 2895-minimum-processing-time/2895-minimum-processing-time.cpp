class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        
        sort(begin(processorTime), end(processorTime));

        sort(begin(tasks), end(tasks));

        int output = 0;

        int j = tasks.size()-1;

        for (int i = 0; i < processorTime.size(); i++)
        {
            if (tasks[j] + processorTime[i] > output)
            {
                output = tasks[j] + processorTime[i];
            }
            j -= 4;
        }

        return output;
    }
};