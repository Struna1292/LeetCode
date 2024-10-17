class Solution {
public:
    int maximumSwap(int num) {
        
        string n = to_string(num);

        vector<int> nextBiggest(n.length(), -1); // index

        int index = n.length()-1;

        for (int i = n.length()-2; i >= 0; i--)
        {
            if (n[i] < n[index])
            {
                nextBiggest[i] = index;
            }
            else if (n[i] > n[index])
            {
                index = i;
            }
        }

        int output = num;

        for (int i = 0; i < nextBiggest.size(); i++)
        {
            if (nextBiggest[i] != -1)
            {
                swap(n[i], n[nextBiggest[i]]);

                output = stoi(n);
                break;
            }
        }

        return output;
    }
};