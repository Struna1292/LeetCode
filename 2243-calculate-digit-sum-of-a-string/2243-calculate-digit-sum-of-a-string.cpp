class Solution {
public:
    string digitSum(string s, int k) {
        
        while (s.length() > k)
        {
            string curr;

            for (int i = 0; i < s.length(); i+=k)
            {
                int border = i + k;
                if (border >= s.length())
                {
                    border = s.length();
                }

                int num = 0;

                for (int j = i; j < border; j++)
                {
                    num += s[j]-'0';
                }

                curr += to_string(num);
            }

            s = curr;
        }

        return s;
    }
};