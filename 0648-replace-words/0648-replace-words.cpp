class Trie {
public:

    struct Node
    {
        Node* child[26] = { nullptr };
        bool isWord = false;
    };

    Node* root;

    Trie() {
        root = new Node;
    }

    
    void insert(string word) {
        Node* curr = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (curr->child[word[i]-'a'] == nullptr)
            {
                curr->child[word[i]-'a'] = new Node;
            }
            curr = curr->child[word[i]-'a'];
        }

        curr->isWord = true;
    }
    
    bool search(string word) 
    {
        Node* curr = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (curr->child[word[i]-'a'] == nullptr)
            {
                return false;
            }
            else
            {
                curr = curr->child[word[i]-'a'];
            }
        }
        
        if (!curr->isWord)
        {
            return false;
        }

        return true;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            if (curr->child[prefix[i]-'a'] == nullptr)
            {
                return false;
            }
            else
            {
                curr = curr->child[prefix[i]-'a'];
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Solution {
public:
    

    string replaceWords(vector<string>& dictionary, string sentence) {

        Trie tree;

        for (int i = 0; i < dictionary.size(); i++)
        {
            tree.insert(dictionary[i]);
        }

        string curr;

        string output;

        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                string check;

                for (int j = 0; j < curr.length(); j++)
                {
                    check.push_back(curr[j]);
                    if (tree.search(check))
                    {
                        break;
                    }
                }

                output += check + " ";

                curr = "";
            }
            else
            {
                curr.push_back(sentence[i]);
            }
        }

        string check;

        for (int j = 0; j < curr.length(); j++)
        {
            check.push_back(curr[j]);
            if (tree.search(check))
            {
                break;
            }
        }

        output += check;


        return output;
    }
};