class Solution {
public:
    string thousandSeparator(int n) {

        string num = to_string(n);

        int j = 1;

        string output;

        for (int i = num.length()-1; i >= 0; i--)
        {
            output.push_back(num[i]);
            if (j % 3 == 0 && i != 0)
            {
                output.push_back('.');
            }
            j++;
        }

        int i = 0;
        j = output.length()-1;

        while (i < j)
        {
            swap(output[i], output[j]);
            i++;
            j--;
        }

        return output;
    }
};