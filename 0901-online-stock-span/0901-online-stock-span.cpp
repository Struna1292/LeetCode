class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int output = 1;

        if (st.empty())
        {
            st.push({price, 1});
        }
        else
        {
            while (!st.empty() && st.top().first <= price)
            {
                output += st.top().second;
                st.pop();
            }
            st.push({price, output});
        }

        return output;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */