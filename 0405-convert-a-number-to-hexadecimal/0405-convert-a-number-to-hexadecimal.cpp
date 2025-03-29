class Solution {
public:
    string toHex(int num) {
        
        string s = bitset<32>(num).to_string();

        char representation[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

        string output;

        for (int i = 0; i < 32; i += 4)
        {
            int curr = 0;

            for (int j = i; j < i+4; j++)
            {
                if (s[j] == '1')
                {
                    curr |= 1;
                }

                if (j+1 != i+4)
                {
                    curr <<= 1;
                }
            }


            if (curr != 0 || output != "")
            {
                output.push_back(representation[curr]);
            }
        }

        if (output == "")
        {
            output = "0";
        }

        return output;
    }
};