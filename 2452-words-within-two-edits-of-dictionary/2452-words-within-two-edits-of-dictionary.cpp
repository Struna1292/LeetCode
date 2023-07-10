class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {

        vector<string> output;

        for (int i = 0; i < queries.size(); i++)
        {
            for (int j = 0; j < dictionary.size(); j++)
            {
                if (queries[i].length() == dictionary[j].length())
                {
                    if (queries[i] == dictionary[j])
                    {
                        output.push_back(queries[i]);
                        break;
                    }
                    else
                    {
                        int counter = 0;
                        for (int k = 0; k < queries[i].length(); k++)
                        {
                            if (queries[i][k] != dictionary[j][k])
                            {
                                counter++;
                            }
                            if (counter >= 3)
                            {
                                break;
                            }
                        }

                        if (counter <= 2)
                        {
                            output.push_back(queries[i]);
                            break;
                        }
                    }
                }
            }
        }

        return output;
    }
};