class Solution {
public:
    struct Node 
    {
        Node* letters[26] = { nullptr };
        bool isWord = false;
    };

    void insertTrie(Node* root, string word)
    {

        for (int i = 0; i < word.length(); i++)
        {
            if (root->letters[word[i]-'a'] == nullptr)
            {
                root->letters[word[i]-'a'] = new Node;
            }
            root = root->letters[word[i]-'a'];
        }

        root->isWord = true;
    }

    void helper(Node* root, string curr, string& output)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->letters[i] != nullptr && root->letters[i]->isWord)
            {
                string curr1 = curr;
                curr1.push_back(i + 'a');
                if (curr1.length() > output.length())
                {
                    output = curr1;
                }

                helper(root->letters[i], curr1, output);
            }
        }
    }

    string longestWord(vector<string>& words) {
        Node* root = new Node;

        for (int i = 0; i < words.size(); i++)
        {
            insertTrie(root, words[i]);
        }

        string output;

        helper(root, "", output);

        return output;
    }
};