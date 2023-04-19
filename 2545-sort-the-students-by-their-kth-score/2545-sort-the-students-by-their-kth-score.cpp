class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {

        for (int i = 0; i < score.size(); i++)
        {
            swap(score[i][0],score[i][k]);
        }

        sort(begin(score), end(score));

        for (int i = 0; i < score.size(); i++)
        {
            swap(score[i][0],score[i][k]);
        }

        int j = score.size()-1;
        for (int i = 0; i < score.size()/2; i++)
        {
            swap(score[i],score[j]);
            j--;
        }

        return score;
    }
};