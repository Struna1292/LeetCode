class Solution {
public:

    int helper(string s, char c, int k)
    {
        int j = 0;
        int counter = 0;
        int biggest = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (j < k)
            {
                counter++;
                if (s[i] == c)
                {
                    j++;
                }
            }
            else
            {
                if (s[i] == c)
                {
                    int index = i - counter;
                    while (s[index] != c)
                    {
                        index++;
                    }
                    counter = i - index;
                }
                else
                {
                    counter++;
                }
            }
            if (counter > biggest)
            {
                biggest = counter;
            }
        }

        return biggest;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int ans1 = helper(answerKey, 'F', k);
        int ans2 = helper(answerKey, 'T', k);

        if (ans1 > ans2)
        {
            return ans1;
        }
        return ans2;
    }
};