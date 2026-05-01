class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    struct Freq {
        int count;
        char c;

        Freq(int count, char c) {
            this->count = count;
            this->c = c;
        }
    };

    string sortVowels(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, int> pos;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                freq[s[i]]++;

                if (!pos.contains(s[i])) {
                    pos[s[i]] = i;
                }
            }
        }

        vector<Freq> freqs;
        for (auto itr = freq.begin(); itr != freq.end(); itr++) {
            freqs.push_back(Freq(itr->second, itr->first));
        }

        sort(begin(freqs), end(freqs), [&pos](const Freq& a, const Freq& b) {
            if (a.count != b.count) {
                return a.count > b.count; 
            }
            return pos[a.c] < pos[b.c]; 
        });

        int currIndex = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                
                s[i] = freqs[currIndex].c;
                freqs[currIndex].count--;
                if (freqs[currIndex].count <= 0) {
                    currIndex++;
                }

            }
        }

        return s;
    }
};