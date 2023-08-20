class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        for (int i = 0; i < words.size(); i++)
        {
            bool match = true;

            int j = 0;
            int k = words[i].length()-1;

            while (j < k)
            {
                if (words[i][j] == words[i][k])
                {
                    j++;
                    k--;
                }
                else
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                return words[i];
            }
        }

        return "";
    }
};