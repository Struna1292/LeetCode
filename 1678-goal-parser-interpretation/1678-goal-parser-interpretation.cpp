class Solution {
public:
    string interpret(string command) {
        string output = "";
        for (int i = 0; i < command.length(); i++)
        {
            if (command[i] == 'G')
            {
                output.push_back(command[i]);
            }
            else if (i + 1 < command.length() && command[i] == '(' && command[i+1] == ')')
            {
                output.push_back('o');
                i++;
            }
            else if (i + 3 < command.length() && command[i] == '(' && command[i+1] == 'a' && command[i+2] == 'l' && command[i+3] == ')')
            {
                output.push_back('a');
                output.push_back('l');
                i = i + 3;
            }
        }
        return output;
    }
};