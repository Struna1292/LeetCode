class Solution {
public:
    struct Triplet
    {
        int first;
        int second;
        int third;

        Triplet(int a, int b, int c)
        {
            first = a;
            second = b;
            third = c;
        }
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        vector<vector<int>> robots(positions.size(), vector<int>());

        for (int i = 0; i < positions.size(); i++)
        {
            robots[i] = {positions[i], healths[i], directions[i], i};
        }

        sort(begin(robots), end(robots));

        stack<Triplet> st;

        for (int i = 0; i < robots.size(); i++)
        {
            if (st.empty())
            {
                st.push({robots[i][1], robots[i][2], robots[i][3]});
            }
            else
            {   
                while (!st.empty() && st.top().second == 'R' && robots[i][2] == 'L' && robots[i][1] > 0)
                {
                    if (st.top().first == robots[i][1])
                    {
                        st.pop();
                        robots[i][1] = 0;
                        break;
                    }
                    else if (st.top().first > robots[i][1])
                    {
                        robots[i][1] = 0;
                        st.top().first--;
                        if (st.top().first == 0)
                        {
                            st.pop();
                        }
                        break;
                    }
                    else
                    {
                        st.pop();
                        robots[i][1]--;
                    }
                }

                if (robots[i][1] > 0)
                {
                    st.push({robots[i][1], robots[i][2], robots[i][3]});
                }
            }
        }


        vector<pair<int,int>> orderHelper; // first original Index second health

        while (!st.empty())
        {
            orderHelper.push_back({st.top().third, st.top().first});

            st.pop();
        }

        sort(begin(orderHelper), end(orderHelper));

        vector<int> output;

        for (int i = 0; i < orderHelper.size(); i++)
        {
            output.push_back(orderHelper[i].second);
        }


        return output;
    }
};