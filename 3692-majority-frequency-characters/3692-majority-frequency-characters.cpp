class Solution {
public:
    string majorityFrequencyGroup(string s) {
        
        unordered_map<char, int> freq;
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        unordered_map<int, string> chars;
        for (auto itr = freq.begin(); itr != freq.end(); itr++) {
            chars[itr->second].push_back(itr->first);
        }

        int prevFreq = -1;
        string prev = "";
        for (auto itr = chars.begin(); itr != chars.end(); itr++) {
            if (prev.length() < itr->second.length() || (prev.length() == itr->second.length() && prevFreq < itr->first)) {
                prev = itr->second;
                prevFreq = itr->first;
            }            
        }

        return prev;
    }
};