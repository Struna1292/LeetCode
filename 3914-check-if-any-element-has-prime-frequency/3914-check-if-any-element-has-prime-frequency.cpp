class Solution {
public:
    bool isPrime(int n) {
        if (n == 1) {
            return false;
        }

        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        
        map<int,int> mp;

        for (int n : nums) {
            mp[n]++;
        }

        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            if (isPrime(itr->second)) {
                return true;
            }
        }

        return false;
    }
};