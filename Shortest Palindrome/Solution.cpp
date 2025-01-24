class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> frequency;
        for( auto c : word )
            frequency[c]++;

        vector<int> freqs;
        for( auto& [c , freq] : frequency )
            freqs.push_back(freq);

        sort(freqs.begin(), freqs.end(), greater<int>());

        int totalPushes = 0;
        int numKeys = 8; 

        for ( size_t i = 0 ; i < freqs.size() ; ++i ) 
        {
            int presses = (i / numKeys) + 1;
            totalPushes += freqs[i] * presses;
        }

        return totalPushes;
    }        
};