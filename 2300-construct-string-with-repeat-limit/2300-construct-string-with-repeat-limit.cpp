class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        int alph[26] = { 0 };

        priority_queue<char> pq;

        for (char c : s)
        {
            alph[c-'a']++;
            if (alph[c-'a'] == 1)
            {
                pq.push(c);
            }   
        }

        string output;
        char prev = 1;


        while (!pq.empty())
        {
            char curr = pq.top();
            pq.pop();

            if (curr != prev)
            {
                if (alph[curr-'a'] > repeatLimit)
                {
                    alph[curr-'a'] -= repeatLimit;
                    for (int i = 0; i < repeatLimit; i++)
                    {
                        output.push_back(curr);
                    }
                    pq.push(curr);
                }
                else
                {
                    for (int i = 0; i < alph[curr-'a']; i++)
                    {
                        output.push_back(curr);
                    }
                    alph[curr-'a'] = 0;
                }
            }
            else
            {
                if (pq.empty())
                {
                    break;
                }
                else
                {
                    output.push_back(pq.top());
                    alph[pq.top()-'a']--;
                    if (alph[pq.top()-'a'] == 0)
                    {
                        pq.pop();
                    }

                    pq.push(curr);
                }
            }
            prev = output[output.length()-1];
        }

        return output;
    }
};