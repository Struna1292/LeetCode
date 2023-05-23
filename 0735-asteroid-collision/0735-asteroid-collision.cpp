class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++)
        {
            if (st.empty())
            {
                st.push(asteroids[i]);
            }
            else if (st.top() > 0 && asteroids[i] > 0 || st.top() < 0 && asteroids[i] < 0 || st.top() < 0 && asteroids[i] > 0)
            {
                st.push(asteroids[i]);
            }
            else
            {
                bool check = true;
                while (!st.empty() && st.top() > 0 && asteroids[i] < 0)
                {
                    int collision = st.top() + asteroids[i];
                    if (collision == 0)
                    {
                        st.pop();
                        check = false;
                        break;
                    }
                    else if (collision > 0)
                    {
                        check = false;
                        break;
                    }
                    else
                    {
                        st.pop();
                    }
                }

                if (check)
                {
                    st.push(asteroids[i]);
                }

            }
        }

        vector<int> answer;
        answer.reserve(st.size());

        while (!st.empty())
        {
            answer.emplace_back(st.top());
            st.pop();
        }

        int i = 0;
        int j = answer.size()-1;
        while (i < j)
        {
            swap(answer[i], answer[j]);
            i++;
            j--;
        }

        return answer;
    }
};