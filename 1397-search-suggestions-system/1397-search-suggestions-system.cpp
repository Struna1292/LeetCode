class Solution {
public:
    struct Node
    {
        bool isWord = false;
        Node* letters[26] = { nullptr };
    };

    void insertWord(Node* root, string word)
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

    void findThree(Node* root, string curr, vector<string>& output)
    {
        if (output.size() == 3)
        {
            return;
        }

        if (root->isWord)
        {
            output.push_back(curr);
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->letters[i] != nullptr)
            {   
                string letter;
                letter.push_back('a'+i);
                findThree(root->letters[i], curr+letter, output);
            }
        }
    }


    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        Node* root = new Node;

        for (int i = 0; i < products.size(); i++)
        {
            insertWord(root, products[i]);
        }

        vector<vector<string>> output;

        Node* start = root; // starting pointer moving for every letter

        string curr;

        for (int i = 0; i < searchWord.length(); i++)
        {

            vector<string> currWords;

            if (start->letters[searchWord[i]-'a'] != nullptr)
            {
                start = start->letters[searchWord[i]-'a'];
                findThree(start, "", currWords);    
            }
            else
            {
                for (int j = output.size(); j < searchWord.length(); j++)
                {
                    output.push_back({});
                }
                break;
            }

            curr.push_back(searchWord[i]);
            for (int j = 0; j < currWords.size(); j++)
            {
                currWords[j] = curr + currWords[j];
            }

            output.push_back(currWords);
        }

        return output;
    }
};