class Solution {
public:
    double average(vector<int>& salary) {
        double salarySum = 0;
        int min = salary[0];
        int max = salary[0];
        for (int i = 0; i < salary.size(); i++)
        {
            if (min > salary[i])
            {
                min = salary[i];
            }
            else if (max < salary[i])
            {
                max = salary[i];
            }
            salarySum += salary[i];
        }
        return (salarySum - max - min) / (salary.size()-2);
    }
};