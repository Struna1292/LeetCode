class Solution {
public:
    string customSortString(string order, string s) {
        
        int alphabet[26] = { 0 };

        for (int i = 0; i < order.length(); i++)
        {
            alphabet[order[i]-'a'] = i+1;
        }
        
        int n = s.length();

        int i,j;
        bool swapped;
        for (i = 0; i < n - 1; i++) 
        {
            swapped = false;

            for (j = 0; j < n - i - 1; j++) 
            {
                if (alphabet[s[j]-'a'] > alphabet[s[j + 1]-'a']) 
                {
                    swap(s[j], s[j + 1]);
                    swapped = true;
                }
            }

            if (swapped == false)
            {
                break;
            }
        }

        return s;
    }
};