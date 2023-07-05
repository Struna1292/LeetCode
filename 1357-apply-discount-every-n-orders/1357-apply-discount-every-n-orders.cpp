class Cashier {
public:

    int n;
    int discount;
    vector<int> products;
    vector<int> prices;
    int counter;

    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        this->products = products;
        this->prices = prices;
        this->counter = 0;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        counter++;
        double bill = 0;
        for (int i = 0; i < product.size(); i++)
        {
            for (int j = 0; j < products.size(); j++)
            {
                if (product[i] == products[j])
                {
                    bill += prices[j] * amount[i];
                    break;
                }
            }
        }
        if (counter % n == 0)
        {
            return (bill * ((double)(100 - discount) / 100));
        }
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */