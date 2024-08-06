class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> alph(26, 0);

        for (char c : word)
        {
            alph[c-'a']++;
        }

        sort(begin(alph), end(alph), greater<int>());

        int counter = 0;
        int place = 1;

        int pushes = 0;

        for (int n : alph)
        {
            pushes += n * place;

            counter++;
            if (counter == 8)
            {
                counter = 0;
                place++;
            }
        }

        return pushes;
    }
};