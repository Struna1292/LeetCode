class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        unordered_set<char> letters;
        unordered_map<char, int> freq1;

        for (int i = 0; i < word1.length(); i++) {
            letters.insert(word1[i]);

            freq1[word1[i]]++;
        }

        unordered_map<char, int> freq2;    
        for (int i = 0; i < word2.length(); i++) {
            if (!letters.contains(word2[i])) {
                return false;
            }

            freq2[word2[i]]++;
        }

        unordered_map<int, int> totalFreqs;

        for (auto itr = freq1.begin(); itr != freq1.end(); itr++) {
            totalFreqs[itr->second]++;
        }
        for (auto itr = freq2.begin(); itr != freq2.end(); itr++) {
            totalFreqs[itr->second]--;
        }

        for (auto itr = totalFreqs.begin(); itr != totalFreqs.end(); itr++) {
            if (itr->second != 0) {
                return false;
            }
        }

        return true;
    }
};