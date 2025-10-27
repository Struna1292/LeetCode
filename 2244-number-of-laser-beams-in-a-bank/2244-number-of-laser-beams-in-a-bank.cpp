class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int prevDevices = 0;
        int output = 0;

        for (int i = 0; i < bank.size(); i++) {
            int currDevices = 0;
            for (int j = 0; j < bank[i].length(); j++) {
                if (bank[i][j] == '1') {
                    currDevices++;
                }
            }

            if (currDevices > 0) {
                output += currDevices * prevDevices;

                prevDevices = currDevices;
            }
        }

        return output;
    }
};