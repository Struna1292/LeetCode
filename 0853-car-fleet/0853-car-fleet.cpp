class Solution {
public:
    int partition(vector<int>& position, int start, int end, vector<int>& times)
    {
    
        int pivot = position[start];
    
        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (position[i] <= pivot)
                count++;
        }
    
        int pivotIndex = start + count;
        swap(position[pivotIndex], position[start]);
        swap(times[pivotIndex], times[start]);
    
        int i = start, j = end;
    
        while (i < pivotIndex && j > pivotIndex) {
    
            while (position[i] <= pivot) {
                i++;
            }
    
            while (position[j] > pivot) {
                j--;
            }
    
            if (i < pivotIndex && j > pivotIndex) {
                swap(position[i], position[j]);
                swap(times[i], times[j]);
                i++;
                j--;
            }
        }
    
        return pivotIndex;
    }
    
    void quickSort(vector<int>& position, int start, int end, vector<int>& times)
    {
    
        if (start >= end)
            return;
    
        int p = partition(position, start, end, times);
    
        quickSort(position, start, p - 1, times);
    
        quickSort(position, p + 1, end, times);
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        quickSort(position, 0, position.size()-1, speed);

        vector<double> times(position.size(), 0);

        for (int i = 0; i < position.size(); i++)
        {
            times[i] = (double)(target - position[i]) / (double)speed[i];
        }

        stack<double> st;
        for (int i = 0; i < times.size(); i++)
        {
            if (st.empty() || st.top() > times[i])
            {
                st.push(times[i]);
            }
            else
            {
                while(!st.empty() && st.top() <= times[i])
                    st.pop();
                st.push(times[i]);
            }
        }

        return st.size();
    }
};