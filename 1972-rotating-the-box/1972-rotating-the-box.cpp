class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        for (int i = 0; i < box.size(); i++)
        {
            queue<int> que;

            for (int j = 0; j < box[i].size(); j++)
            {
                if (box[i][j] == '#') // stone
                {
                    que.push(j);
                }
                else if (box[i][j] == '.') // empty
                {
                    if (!que.empty())
                    {
                        swap(box[i][que.front()], box[i][j]);
                        que.push(j);
                        que.pop();
                    }
                }
                else // obstacle
                {
                    while (!que.empty())
                    {
                        que.pop();
                    }
                }
            }
        }


        vector<vector<char>> output(box[0].size(), vector<char>(box.size(), '.'));

        int l = box.size()-1;
        for (int i = 0; i < box.size(); i++)
        {
            int k = 0;
            for (int j = 0; j < box[i].size(); j++)
            {
                output[k][l] = box[i][j];
                k++;
            }
            l--;
        }

        return output;
    }
};