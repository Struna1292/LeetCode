class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> output;

        string curr;
        string empty;
        int biggest = 0;

        for (int i = s.length()-1; i >= 0; i--)
        {   
            if (s[i] == ' ')
            {
                int k = 0;
                for (int j = curr.length(); j >= 0; j--)
                {
                    if (output.size() < k+1)
                    {
                        output.push_back(empty);
                    }
                    output[k].push_back(curr[j]);
                    k++;
                }
                
                if (curr.length() > biggest)
                {
                    biggest = curr.length();
                }
                else if (curr.length() < biggest)
                {
                    for (int j = 0; j < biggest - curr.length(); j++)
                    {
                        if (output.size() < k+1)
                        {
                            output.push_back(empty);
                        }
                        output[k].push_back(' ');
                        k++;
                    }
                }

                curr = empty;
            }
            else
            {
                curr.push_back(s[i]);
            }
        }

        int k = 0;
        for (int j = curr.length(); j >= 0; j--)
        {
            if (output.size() < k+1)
            {
                output.push_back(empty);
            }
            output[k].push_back(curr[j]);
            k++;
        }
                
        if (curr.length() > biggest)
        {
            biggest = curr.length();
        }
        else if (curr.length() < biggest)
        {
            for (int j = 0; j < biggest - curr.length(); j++)
            {
                if (output.size() < k+1)
                {
                    output.push_back(empty);
                }
                output[k].push_back(' ');
                k++;
            }
        }

        for (int i = 0; i < output.size(); i++)
        {
            int j = 0;
            int k = output[i].length()-1;
            while (j < k)
            {
                swap(output[i][j], output[i][k]);
                j++;
                k--;
            }
        }

        output.erase(output.begin());
        
        return output;
    }
};