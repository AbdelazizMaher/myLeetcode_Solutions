class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;

        string sentence = s1 + " " + s2;
        string delimiter {" "};

        size_t start = 0, end;
        while ((end = sentence.find(delimiter, start)) != string::npos) {
            string word = sentence.substr(start, end - start);
            freq[word]++;
            start = end + 1;
        }

        string lastWord = sentence.substr(start);
        freq[lastWord]++;

        vector<string> unCommon{};
        for (auto& [string, common] : freq) {
            if (common == 1) {
                unCommon.push_back(string);
            }
        }

        return unCommon;
    }
};