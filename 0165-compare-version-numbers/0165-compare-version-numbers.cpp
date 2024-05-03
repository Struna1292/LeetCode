class Solution {
public:
    vector<int> convertVersionToVector(string version)
    {
        vector<int> v;

        string curr;

        for (int i = 0; i < version.length(); i++)
        {
            if (version[i] != '.')
            {
                curr.push_back(version[i]);
            }
            else
            {
                int num = stoi(curr);
                v.push_back(stoi(curr));
                curr = "";
            }
        }
        v.push_back(stoi(curr));

        return v;
    }

    int compareVersion(string version1, string version2) {
        
        vector<int> v1 = convertVersionToVector(version1);
        vector<int> v2 = convertVersionToVector(version2);


        while (v1.size() > v2.size())
        {
            v2.push_back({0});
        }

        while (v2.size() > v1.size())
        {
            v1.push_back({0});
        }


        int i = 0;

        while (i < v1.size())
        {
            if (v1[i] < v2[i])
            {
                return -1;
            }
            else if (v1[i] > v2[i])
            {
                return 1;
            }
            else
            {
                i++;
            }
        }

        return 0;
    }
};