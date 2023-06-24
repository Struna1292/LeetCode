class Solution {
public:

    vector<int> extract(string num1)
    {
        vector<int> nums1;
        int num = 0;
        bool minus = false;
        for (int i = 0; i < num1.length(); i++)
        {
            if (num1[i] == '-')
            {
                minus = true;
            }
            else if (num1[i] == '+' || num1[i] == 'i')
            {
                num /= 10;
                if (minus)
                {
                    num *= -1;
                }
                nums1.push_back(num);
                num = 0;
                minus = false;
            }
            else
            {
                num += (num1[i]-'0');
                num *= 10;
            }
        }
        
        return nums1;
    }

    string complexNumberMultiply(string num1, string num2) {
        
        vector<int> nums1 = extract(num1);

        vector<int> nums2 = extract(num2);

        int real = ((nums1[0]*nums2[0]) + (nums1[1]*nums2[1])*(-1));
        int imaginary = nums1[0]*nums2[1] + nums1[1]*nums2[0];

        string output = to_string(real) + "+" + to_string(imaginary) + "i";

        return output;
    }
};