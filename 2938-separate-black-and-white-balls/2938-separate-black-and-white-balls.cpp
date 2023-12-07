class Solution {
public:
    long long minimumSteps(string s) {
        long long output = 0;

        long long curr = 0;

        for (int i = s.length()-1; i >= 0; i--)
        {
          if (s[i] == '0')
          {
            curr++;
          }
          else
          {
            output += curr;
          }
        }

        return output;
    }
};