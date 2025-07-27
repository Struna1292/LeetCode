class Solution {
public:
    struct TrieNode {
        TrieNode* letters[26] = { nullptr };
        bool isWord = false;
    };

    void insert(TrieNode* curr, string& word) {

        for (int i = 0; i < word.length(); i++) {
            if (curr->letters[word[i]-'a'] == nullptr) {
                curr->letters[word[i]-'a'] = new TrieNode;
            }
            curr = curr->letters[word[i]-'a'];
        }

        curr->isWord = true;
    }

    void DFS(int i, int j, vector<vector<char>>& board, 
    vector<vector<bool>>& seen, string currWord, TrieNode* prevChar, vector<string>& foundWords) {
        if (i < 0 || i >= board.size() || 
            j < 0 || j >= board[i].size() ||
            seen[i][j]) {
            return;
        }

        TrieNode* currChar = prevChar->letters[board[i][j]-'a'];
        if (currChar == nullptr) {
            return;
        }

        currWord.push_back(board[i][j]);
        seen[i][j] = true;

        DFS(i+1, j, board, seen, currWord, currChar, foundWords);
        DFS(i-1, j, board, seen, currWord, currChar, foundWords);
        DFS(i, j+1, board, seen, currWord, currChar, foundWords);
        DFS(i, j-1, board, seen, currWord, currChar, foundWords);

        seen[i][j] = false;
        if (currChar->isWord) {
            foundWords.push_back(currWord);
            currChar->isWord = false; // change so we dont add the same word multiple times
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            insert(root, words[i]);
        }

        vector<string> foundWords;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                vector<vector<bool>> seen(board.size(), vector<bool>(board[i].size(), false));
                DFS(i, j, board, seen, "", root, foundWords);
            }
        }

        return foundWords;
    }
};