class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        vector<string> words;

        string curr;

        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == ' ')
            {
                words.push_back(curr);
                curr = "";
            }
            else
            {
                curr.push_back(sentence[i]);
            }
        }

        words.push_back(curr);

        for (int i = 1; i < words.size(); i++)
        {
            if (words[i][0] != words[i-1][words[i-1].length()-1])
            {
                return false;
            }
        }

        if (words[words.size()-1][words[words.size()-1].length()-1] != words[0][0])
        {
            return false;
        }

        return true;
    }
};