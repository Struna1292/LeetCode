class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int output = -1000;

        // there will be k paths total

        for (int i = 0; i < k; i++)
        {
            // starting from back we calculate score for every starting point

            int curr = 0;
            for (int j = energy.size()-1-i; j >= 0; j -= k)
            {
                curr += energy[j];

                if (curr > output)
                {
                    output = curr;
                }
            }
        }

        return output;
    }
};