class Solution {
public:
    int getIndex(char c) {
        if (c >= 'a' && c <= 'z') {
            return c-'a';
        }
        else {
            return c-'A'+26;
        }
    }

    bool isVowel(char c, unordered_set<char>& vowels) {
        
        if (vowels.find(c) != vowels.end()) {
            return true;
        }

        return false;
    }

    struct TrieNode {
        TrieNode* childs[52] = { nullptr };
        bool isWord = false;
        int index = -1;
    };

    void insert(TrieNode* root, string s, int index) {

        TrieNode* curr = root;

        for (int i = 0; i < s.length(); i++) {
            if (curr->childs[getIndex(s[i])] == nullptr) {
                curr->childs[getIndex(s[i])] = new TrieNode;
            }
            curr = curr->childs[getIndex(s[i])];
        }
        if (!curr->isWord) {
            curr->isWord = true;
            curr->index = index;
        }   
    }

    char oppositeCase(char c) {
        if (c >= 'a' && c <= 'z') {
            return c-32;
        }
        else {
            return c+32;
        }
    }

    void caseSensitiveHelper(TrieNode* curr, string& s, int index, stack<char>& path, string& found, int& foundIndex) {
        if (curr == nullptr) {
            return;
        }

        // check if this is last index
        if (index+1 == s.length()) {
            if (curr->isWord && (foundIndex == -1 || curr->index < foundIndex)) {
                found = s;
                foundIndex = curr->index;
                stack<char> currStack = path;
                for (int i = found.length()-1; i >= 0; i--) {
                    found[i] = currStack.top();
                    currStack.pop();
                }
            }
            return;
        }


        path.push(s[index+1]);
        caseSensitiveHelper(curr->childs[getIndex(s[index+1])], s, index+1, path, found, foundIndex);
        path.pop();

        char opp = oppositeCase(s[index+1]);
        path.push(opp);
        caseSensitiveHelper(curr->childs[getIndex(opp)], s, index+1, path, found, foundIndex);
        path.pop();
    }

    void vowelsHelper(TrieNode* curr, string& s, int index, stack<char>& path, string& found, int& foundIndex, unordered_set<char>& vowels) {
        if (curr == nullptr) {
            return;
        }

        // check if this is last index
        if (index+1 == s.length()) {
            if (curr->isWord && (foundIndex == -1 || curr->index < foundIndex)) {
                found = s;
                foundIndex = curr->index;
                stack<char> currStack = path;
                for (int i = found.length()-1; i >= 0; i--) {
                    found[i] = currStack.top();
                    currStack.pop();
                }
            }
            return;
        }

        if (isVowel(s[index+1], vowels)) {
            string lowerCaseVowels = "aeiou";

            for (int i = 0; i < lowerCaseVowels.length(); i++) {
                path.push(lowerCaseVowels[i]);
                vowelsHelper(curr->childs[getIndex(lowerCaseVowels[i])], s, index+1, path, found, foundIndex, vowels);
                path.pop();

                char opp = oppositeCase(lowerCaseVowels[i]);
                path.push(opp);
                vowelsHelper(curr->childs[getIndex(opp)], s, index+1, path, found, foundIndex, vowels);
                path.pop();
            }
        }
        else {
            path.push(s[index+1]);
            vowelsHelper(curr->childs[getIndex(s[index+1])], s, index+1, path, found, foundIndex, vowels);
            path.pop();

            char opp = oppositeCase(s[index+1]);
            path.push(opp);
            vowelsHelper(curr->childs[getIndex(opp)], s, index+1, path, found, foundIndex, vowels);
            path.pop();
        }
    }

    void contains(TrieNode* root, string s, string& found, unordered_set<char>& vowels) {
        TrieNode* curr = root;

        // first check if it exists unchanged
        for (int i = 0; i < s.length(); i++) {
            if (curr == nullptr) {
                break;
            }
            curr = curr->childs[getIndex(s[i])];
        }

        if (curr != nullptr && curr->isWord) {
            found = s;
            return;
        }

        // check if it exists with case sensitive error
        stack<char> path;
        int foundIndex = -1;
        caseSensitiveHelper(root, s, -1, path, found, foundIndex);

        if (found.length() > 0) {
            return;
        }

        // check vowels and case sensitive
        vowelsHelper(root, s, -1, path, found, foundIndex, vowels);

    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        string allVowels = "aeiouAEIOU";
        unordered_set<char> vowels;
        for (int i = 0; i < allVowels.length(); i++) {
            vowels.insert(allVowels[i]);
        }

        TrieNode* root = new TrieNode;

        for (int i = 0; i < wordlist.size(); i++) {
            insert(root, wordlist[i], i);
        }

        vector<string> output;

        for (int i = 0; i < queries.size(); i++) {
            string found = "";
            contains(root, queries[i], found, vowels);
            if (found.length() > 0) {
                output.push_back(found);
            }
            else {
                output.push_back("");
            }
        }

        return output;
    }
};