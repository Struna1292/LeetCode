class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        class Occurr
        {
            public:
                int num;
                vector<int> indexes;
        };

        vector<Occurr> occurrences;
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            counter = 0;
            for (int j = 0; j < occurrences.size(); j++)
            {
                if (nums[i] == occurrences[j].num)
                {
                    occurrences[j].indexes.push_back({i});
                    break;
                }
                else
                {
                    counter++;
                }
            }
            if (counter == occurrences.size())
            {
                occurrences.push_back({nums[i],{i}});
            }
        }

        int index = 0;
        int biggest = 0;

        for (int i = 0; i < occurrences.size(); i++)
        {
            if (occurrences[i].indexes.size() > biggest)
            {
                biggest = occurrences[i].indexes.size();
                index = i;
            }
            else if (occurrences[i].indexes.size() == biggest)
            {
                if (occurrences[index].indexes[occurrences[index].indexes.size()-1] - occurrences[index].indexes[0] > occurrences[i].indexes[occurrences[i].indexes.size()-1] - occurrences[i].indexes[0])
                {
                    biggest = occurrences[i].indexes.size();
                    index = i;
                }
            }
            
            cout << "num: " << occurrences[i].num << " indexy: ";
            for (int j = 0; j < occurrences[i].indexes.size(); j++)
            {
                cout << occurrences[i].indexes[j] << " ";
            }
            cout << endl;
        }


        return occurrences[index].indexes[occurrences[index].indexes.size()-1]+1 - occurrences[index].indexes[0];
    }
};