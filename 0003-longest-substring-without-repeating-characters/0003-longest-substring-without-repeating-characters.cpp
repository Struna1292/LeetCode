class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        bool curr[128] = { false };
        
        int i = 0;
        while (i < s.length())
        {
            if (curr[s[i]])
            {
                break;
            }
            else
            {
                curr[s[i]] = true;
            }
            i++;
        }

        cout << "!!! i: " << i << endl;

        int currLength = i;
        int longest = i;

        for (; i < s.length(); i++)
        {   
            if (curr[s[i]])
            {
                int j = i - currLength;
                while (s[i] != s[j])
                {
                    curr[s[j]] = false;
                    currLength--;
                    j++;
                }
            }
            else
            {
                curr[s[i]] = true;
                currLength++;
                if (currLength > longest)
                {
                    longest = currLength;
                }
            }
        }

        return longest;
    }
};