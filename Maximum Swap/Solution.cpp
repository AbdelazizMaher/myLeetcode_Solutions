class Solution {
public:
    int maximumSwap(int num) {
        string toSwap = to_string(num);
        
        for (int i = 1; i < toSwap.length(); ++i) {
            string sub = toSwap.substr(i);
            auto max = max_element(sub.rbegin(), sub.rend());
            int index = (max.base() - 1 - sub.begin()) + i;

            if (toSwap[index] > toSwap[i - 1]) {
                swap(toSwap[index], toSwap[i - 1]);
                break;
            }
        }
        return stoi(toSwap);
    }
};