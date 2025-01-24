class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1, 0);
        vector<int> out(n + 1, 0);
        int judge = -1;

        for (auto rel : trust) {
            out[rel[0]]++;
            in[rel[1]]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (in[i] == (n - 1)  && out[i] == 0) {
                judge = i;
                break;
            }
        }
        return judge;
    }
};