class Solution {
public:
    string reverseStr(string s, int k) {
        
        for (int i = 0; i < s.length(); i+=2*k)
        {
            int j = i;
            int l = i+k-1;

            if (l >= s.length())
            {
                l = s.length()-1;
            }


            while (j < l)
            {
                swap(s[j], s[l]);
                j++;
                l--;
            }
        }
        
        return s;
    }
};