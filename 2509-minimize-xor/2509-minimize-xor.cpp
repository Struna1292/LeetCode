class Solution {
public:
    int minimizeXor(int num1, int num2) {

        string n1 = bitset<64>(num1).to_string();
        string n2 = bitset<64>(num2).to_string();

        int bitCounter = 0;

        for (int i = 0; i < 64; i++)
        {
            if (n2[i] == '1')
            {
                bitCounter++;
            }
        }

        string numBinary(64, '0');

        for (int i = 0; i < 64; i++)
        {
            if (n1[i] == '1')
            {
                if (bitCounter > 0)
                {
                    numBinary[i] = '1';
                    bitCounter--;
                }
                else
                {
                    break;
                }
            }
        }

        for (int i = 63; i >= 0; i--)
        {
            if (n1[i] == '0')
            {
                if (bitCounter > 0)
                {
                    numBinary[i] = '1';
                    bitCounter--;
                }
                else
                {
                    break;
                }
            }
        }

        return stoi(numBinary, nullptr, 2);
    }
};