class Solution {
public:
    int getDiff(char base, int size, unordered_map<char, int>& um) {
        int output = 0;

        for (int i = 0; i < size/2; i++) {
            char start = base + i;
            char end = base + (size - 1) - i;

            output += abs(um[start] - um[end]);
        }

        return output;
    }

    int mirrorFrequency(string s) {
        
        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        int output = getDiff('a', 26, freq);
        output += getDiff('0', 10, freq);

        return output;
    }
};