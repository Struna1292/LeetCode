class NumberContainers {
public:
    map<int, int> indexNumber;
    map<int, set<int>> numberIndex;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        // erase number from old index if exists
        numberIndex[indexNumber[index]].erase(index);
        // insert or replace number assigned to index
        indexNumber[index] = number;
        // insert or replace index assigned to number


        numberIndex[number].insert(index);
    }
    
    int find(int number) {
        int index = -1;

        if (!numberIndex[number].empty())
        {
            return *(numberIndex[number].begin());
        }

        return index;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */