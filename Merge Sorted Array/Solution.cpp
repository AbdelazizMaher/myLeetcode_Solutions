class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        while (i < m && !minHeap.empty()) {
            if (nums1[i] > minHeap.top()) {
                int temp = nums1[i];
                nums1[i] = minHeap.top();
                minHeap.pop();
                minHeap.push(temp);
            }
            i++;
        }

        while (!minHeap.empty()) {
            nums1[i++] = minHeap.top();
            minHeap.pop();
        }
    }
};