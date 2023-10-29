class Solution {
public:
    bool isSpecial(char c)
    {
        if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '+')
        {
            return true;
        }
        
        return false;
    }

    bool strongPasswordCheckerII(string password) {
        
        if (password.length() < 8)
        {
            return false;
        }

        bool lowerCase = false;
        bool upperCase = false;
        bool digit = false;
        bool special = false;

        for (int i = 0; i < password.length(); i++)
        {
            if (password[i] >= 'a' && password[i] <= 'z')
            {
                lowerCase = true;
            }
            else if (password[i] >= 'A' && password[i] <= 'Z')
            {   
                upperCase = true;
            }
            else if (password[i] >= '0' && password[i] <= '9')
            {
                digit = true;
            }
            else if (isSpecial(password[i]))
            {
                special = true;
            }

            if (i >= 1 && password[i-1] == password[i])
            {
                return false;
            }
        }
        

        if (!lowerCase || !upperCase || !digit || !special)
        {
            return false;
        }
        
        return true;
    }
};