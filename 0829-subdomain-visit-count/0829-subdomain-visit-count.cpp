class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map <string, int> mp; // domain and number of visits

        for (int i = 0; i < cpdomains.size(); i++)
        {
            string visits;

            int j = 0;
            
            while (cpdomains[i][j] != ' ')
            {
                visits.push_back(cpdomains[i][j]);
                j++;
            }

            int num = stoi(visits);

            string currDomain;

            string curr;

            j = cpdomains[i].size()-1;

            while (cpdomains[i][j] != ' ')
            {
                if (cpdomains[i][j] == '.')
                {
                    int k = 0;
                    int l = curr.length()-1;

                    while (k < l)
                    {
                        swap(curr[k], curr[l]);
                        k++;
                        l--;
                    }
                    
                    if (currDomain.length() >= 1)
                    {
                        currDomain = curr + "." + currDomain;
                    }
                    else
                    {
                        currDomain = curr;
                    }

                    mp[currDomain] += num;

                    curr = "";
                }
                else
                {
                    curr.push_back(cpdomains[i][j]);
                }
                j--;
            }

            int k = 0;
            int l = curr.length()-1;

            while (k < l)
            {
                swap(curr[k], curr[l]);
                k++;
                l--;
            }
                    
            if (currDomain.length() >= 1)
            {
                currDomain = curr + "." + currDomain;
            }
            else
            {
                currDomain = curr;
            }

            mp[currDomain] += num;

        }

        map<string, int>::iterator itr;
        vector<string> output;

        for (itr = mp.begin(); itr != mp.end(); itr++)
        {
            output.push_back(to_string(itr->second) + " " + itr->first);
        }

        return output;
    }
};