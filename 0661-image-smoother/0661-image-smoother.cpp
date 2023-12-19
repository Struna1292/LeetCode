class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> output = img;

        for (int i = 0; i < img.size(); i++)
        {
            for (int j = 0; j < img[i].size(); j++)
            {
                int curr = img[i][j];
                int counter = 1;

                if (i-1 >= 0)
                {
                    if (j-1 >= 0)
                    {
                        curr += img[i-1][j-1];
                        counter++;
                    }

                    curr += img[i-1][j];
                    counter++;

                    if (j+1 < img[i].size())
                    {
                        curr += img[i-1][j+1];
                        counter++;
                    }
                }

                if (j-1 >= 0)
                {
                    curr += img[i][j-1];
                    counter++;
                }

                if (j+1 < img[i].size())
                {
                    curr += img[i][j+1];
                    counter++;
                }

                if (i+1 < img.size())
                {
                    if (j-1 >= 0)
                    {
                        curr += img[i+1][j-1];
                        counter++;
                    }

                    curr += img[i+1][j];
                    counter++;

                    if (j+1 < img[i].size())
                    {
                        curr += img[i+1][j+1];
                        counter++;
                    }
                }

                output[i][j] = curr / counter;

            }
        }

        return output;
    }
};