class Solution {
public:
    double average(vector<int>& salary) {
        double salarySum = 0;
        sort(begin(salary), end(salary));
        for (int i = 1; i < salary.size()-1; i++)
        {
            salarySum += salary[i];
        }
        return salarySum / (salary.size() - 2);
    }
};