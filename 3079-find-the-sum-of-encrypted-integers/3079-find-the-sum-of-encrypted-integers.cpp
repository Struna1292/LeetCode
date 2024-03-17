class Solution {
public:
    int encrypt(int num)
    {
        string n = to_string(num);

        char largest = n[0];

        for (int i = 1; i < n.length(); i++)
        {
            if (n[i] > largest)
            {
                largest = n[i];
            }
        }

        for (int i = 0; i < n.length(); i++)
        {
            n[i] = largest;
        }

        return stoi(n);
    }

    int sumOfEncryptedInt(vector<int>& nums) {
        int output = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            output += encrypt(nums[i]);
        }

        return output;
    }
};