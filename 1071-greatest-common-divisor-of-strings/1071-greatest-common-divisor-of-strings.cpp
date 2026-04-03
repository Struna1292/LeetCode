class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() > str2.length()) {
            swap(str1, str2);
        }

        for (int length = str1.length(); length > 0; length--) {
            if (str1.length() % length != 0 || str2.length() % length != 0) {
                continue;
            }
            
            bool matching = true;
            for (int startIndex = 0; startIndex + length <= str2.length(); startIndex += length) {
                if (!matching) {
                    break;
                }

                for (int j = 0; j < length; j++) {
                    if (str1[j] != str2[startIndex+j]) {
                        matching = false;
                        break;
                    }
                }
            }

            for (int startIndex = 0; startIndex + length <= str1.length(); startIndex += length) {
                if (!matching) {
                    break;
                }

                for (int j = 0; j < length; j++) {
                    if (str1[j] != str1[startIndex+j]) {
                        matching = false;
                        break;
                    }
                }
            }

            if (matching) {
                string output;

                for (int i = 0; i < length; i++) {
                    output.push_back(str1[i]);
                }
                return output;
            }
        }

        return "";
    }
};