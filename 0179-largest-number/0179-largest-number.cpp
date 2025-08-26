class Solution {
public:
    struct comparator {
        bool operator()(string& a, string& b) {
            int i = 0;
            while (i < a.length() && i < b.length()) {
                if (a[i] > b[i]) {
                    return true;
                }
                else if (a[i] < b[i]) {
                    return false;
                }
                i++;
            }

            if (a.length() != b.length()) {
                string checkA = a+b;
                string checkB = b+a;

                for (int j = 0; j < checkA.length(); j++) {
                    if (checkA[j] > checkB[j]) {
                        return true;
                    }
                    else if (checkA[j] < checkB[j]) {
                        break;
                    }
                }
            }
            return false;
        }
    };

    string largestNumber(vector<int>& numbers) {

        vector<string> nums;
        
        for (int i = 0; i < numbers.size(); i++) {
            nums.push_back(to_string(numbers[i]));
        }

        sort(begin(nums), end(nums), comparator());

        string output;
        bool leadingZeros = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].length(); j++) {
                if (output.length() == 0 && nums[i][j] == '0') {
                    continue;
                }
                output.push_back(nums[i][j]);
            }
        }

        if (output.length() == 0) {
            output = "0";
        }

        return output;
    }
};