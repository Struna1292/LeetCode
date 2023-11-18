class OrderedStream {
public:
    vector<string> stream;
    int i = 0;

    OrderedStream(int n) {
        vector<string> allocation(n, "");
        stream = allocation;
    }
    
    vector<string> insert(int idKey, string value) {
        
        stream[idKey-1] = value;

        vector<string> output;

        while (i < stream.size() && stream[i] != "")
        {
            output.push_back(stream[i]);
            i++;
        }

        return output;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */