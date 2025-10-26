class Bank {
public:
    vector<long long> accounts;

    Bank(vector<long long>& balance) {
        accounts = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > accounts.size() || account2 > accounts.size()) {
            return false;
        }
        account1--;
        account2--;

        if (accounts[account1] - money < 0) {
            return false;
        }

        accounts[account1] -= money;
        accounts[account2] += money;

        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > accounts.size()) {
            return false;
        }
        account--;
        
        accounts[account] += money;

        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > accounts.size()) {
            return false;
        }
        account--;

        if (accounts[account] - money < 0) {
            return false;
        }        

        accounts[account] -= money;

        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */