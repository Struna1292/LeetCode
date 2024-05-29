class Solution {
public:
    void divideByTwo(string& s)
    {
        char prev = '0';

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1' && prev == '0')
            {
                s[i] = '0';
                prev = '1';
            }
            else if (s[i] == '0' && prev == '1')
            {
                s[i] = '1';
                prev = '0';
            }
        }
    }

    void addOne(string& s)
    {   
        for (int i = s.length()-1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
                return;
            }
            else
            {
                s[i] = '0';
            }
        }

        s.push_back('0');
        s[0] = '1';
    }

    int numSteps(string s) {
        
        int counter = 0;

        while (true)
        {
            if (s[s.length()-1] == '1')
            {
                bool found = false;

                for (int i = 0; i < s.length()-1; i++)
                {
                    if (s[i] == '1')
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    break;
                }

                addOne(s);
            }
            else
            {
                divideByTwo(s);
            }

            counter++;
        }

        return counter;
    }
};