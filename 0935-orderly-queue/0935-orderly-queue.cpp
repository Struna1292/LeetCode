class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) { // need to decide which is the best starting point
            
            // if there is multiple smallest element store them in linked list
            // then iterate through chars and check which one is the best

            list<int> indexes; // store best indexes

            for (int i = 0; i < s.length(); i++) {
                if (indexes.empty()) {
                    indexes.push_back(i);
                }
                else {
                    if (s[indexes.front()] == s[i]) {
                        indexes.push_back(i);
                    }
                    else if (s[indexes.front()] > s[i]) {
                        indexes.clear();
                        indexes.push_back(i);
                    }
                }
            }

            // iterate throught all string indexes until there is only one left or pick the first one if they are all equal
            // inside loop iterate throught all indexes of smallest character if its worse remove it

            for (int i = 1; i < s.length(); i++) {
                if (indexes.size() <= 1) {
                    break;
                }

                list<int> currBest;

                for (auto itr = indexes.begin(); itr != indexes.end(); itr++) {
                    int currIndex = *itr;
                    if (currBest.empty()) {
                        currBest.push_back(currIndex);
                    }
                    else {

                        char currChar = s[(currIndex+i) % s.length()];
                        char bestChar = s[(currBest.front()+i) % s.length()];

                        if (currChar == bestChar) {
                            currBest.push_back(currIndex);
                        }
                        else if (currChar < bestChar) {
                            currBest.clear();
                            currBest.push_back(currIndex);
                        }
                    }
                }

                indexes = currBest;
            }

            int index = *(indexes.begin());
            string output(s.length(), ' ');

            for (int i = 0; i < s.length(); i++) {
                output[i] = s[(i+index) % s.length()];
            }

            return output;
        }

        // with k > 1 we can setup any possible combination
        // we could simply sort(begin(s), end(s))
        // but it`s way slower than counting and replacing

        int alph[26] = { 0 };

        for (int i = 0; i < s.length(); i++) {
            alph[s[i]-'a']++;
        }

        int index = 0;

        for (int i = 0; i < 26; i++) {
            while (alph[i] > 0) {
                alph[i]--;
                s[index] = (i+'a');
                index++;
            }
        }
        return s;
    }
};