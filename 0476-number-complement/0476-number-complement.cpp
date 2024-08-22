class Solution {
public:
    int findComplement(int num) {

        string numString = bitset<32>(num).to_string();
        
        int i = 0;

        while (numString[i] == '0' && i < 32)
        {
            i++;
        }

        for (; i < 32; i++)
        {
            if (numString[i] == '0')
            {
                numString[i] = '1';
            }
            else
            {
                numString[i] = '0';
            }
        }

        int output = bitset<32>(numString).to_ulong(); 

        return output;
    }
};