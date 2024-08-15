class KthLargest {
public:
    int kthLargest;
    int m_k;
    vector<int> m_nums {};
    KthLargest(int k, vector<int>& nums) {
        m_nums = nums;
        m_k = k; 

        sort(m_nums.begin(), m_nums.end(), [](int& a, int& b) {
            return a > b;
        });

         if (m_nums.size() >= m_k)
            kthLargest = m_nums[k-1];
    }
    
    int add(int val) {
        auto it = lower_bound(m_nums.begin(), m_nums.end(), val, [](const int& a, const int& b) {
            return a > b; 
        });

        m_nums.insert(it, val);

        kthLargest = m_nums[m_k-1];
        return kthLargest;    
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */