class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        int answer = 0;

        for (int i = 0; i < words.size(); i++)
        {
            int counter = 0;
            for (int j = 0; j < pref.length(); j++)
            {
                if (words[i][j] == pref[j])
                {
                    counter++;
                }
                else
                {
                    counter = 0;
                    break;
                }
            }

            if (counter == pref.length())
            {
                answer++;
            }
        }

        return answer;
    }
};