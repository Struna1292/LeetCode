class Solution {
public:
    int vowelIndex(char c) {
        string vowels = "AEIOUaeiou";

        for (int i = 0; i < vowels.length(); i++) {
            if (vowels[i] == c) {
                return i;
            }
        }   

        return -1;
    } 

    string sortVowels(string s) {
        
        // store vowels indexes
        vector<int> indexes;
        int vowelsCount[10] = { 0 };

        for (int i = 0; i < s.length(); i++) {
            int index = vowelIndex(s[i]);
            if (index != -1) {
                vowelsCount[index]++;
                indexes.push_back(i);
            }
        }

        string vowels = "AEIOUaeiou";
        for (int i = 0; i < indexes.size(); i++) {
            int currIndex = indexes[i];

            char c = vowels[0];
            for (int j = 0; j < vowels.length(); j++) {
                if (vowelsCount[j] > 0) {
                    c = vowels[j];
                    vowelsCount[j]--;
                    break;
                }
            }

            s[currIndex] = c;
        }

        return s;
    }
};