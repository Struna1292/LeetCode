class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        string s = to_string(num);
        
        int output = 0;

        for (int i = 0; i < s.length()-k+1; i++)
        {   
            string curr;
            for (int j = i; j < i+k; j++)
            {   
                curr.push_back(s[j]);
            }

            int check = stoi(curr);

            if (check != 0 && num % check == 0)
            {
                output++;
            }
        }

        return output;
    }
};