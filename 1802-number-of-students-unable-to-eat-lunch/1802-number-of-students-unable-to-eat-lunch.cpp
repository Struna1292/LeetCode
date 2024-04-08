class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> s;

        for (int i = 0; i < students.size(); i++)
        {
            s.push(students[i]);
        }


        for (int i = 0; i < sandwiches.size(); i++)
        {
            int j = s.size();

            while (j > 0)
            {
                if (s.front() == sandwiches[i])
                {
                    s.pop();
                    break;
                }
                else
                {
                    s.push(s.front());
                    s.pop();
                }
                j--;
            }

            if (j == 0)
            {
                break;
            }
        }

        return s.size();
    }
};