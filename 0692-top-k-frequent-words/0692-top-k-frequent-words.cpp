class Solution {
public:
    struct TrieNode {
        TrieNode* childrens[26] = { nullptr }; 
        int isWord = 0;
    };

    struct Comparator {
        bool operator()(pair<int, string> a, pair<int, string> b) const {
            if (a.first > b.first || (a.first == b.first && a.second < b.second)) {
                return true;
            }
            return false;
        }
    };

    void insert(TrieNode* root, string word) {
        TrieNode* curr = root;

        for (int i = 0; i < word.length(); i++) {
            if (curr->childrens[word[i]-'a'] == nullptr) {
                curr->childrens[word[i]-'a'] = new TrieNode();
            }
            curr = curr->childrens[word[i]-'a'];
        }

        curr->isWord++;
    }

    void getAllHelper(TrieNode* currNode, string curr, priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator>& pq, char c, int& k) {
        if (currNode == nullptr) {
            return;
        }

        curr.push_back(c);
        if (currNode->isWord != 0) {
            if (pq.size() < k) {
                pq.push({currNode->isWord, curr});
            } else if (pq.top().first < currNode->isWord) {
                pq.pop();
                pq.push({currNode->isWord, curr});
            }
        }

        for (int i = 0; i < 26; i++) {
            getAllHelper(currNode->childrens[i], curr, pq, i+'a', k);
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        TrieNode* root = new TrieNode();

        for (int i = 0; i < words.size(); i++) {
            insert(root, words[i]);
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator> pq; // min heap

        for (int i = 0; i < 26; i++) {
            getAllHelper(root->childrens[i], "", pq, i+'a', k);
        }

        vector<string> output(k);

        for (int i = k-1; i >= 0; i--) {
            output[i] = pq.top().second;
            pq.pop();
        }

        return output;
    }
};