class Solution {
    public int removeElement(int[] nums, int val) {
        int size = nums.length;
        int i = 0;
        while (i < size) {
            if (nums[i] == val) {
                nums[i] = nums[size - 1];
                size--;
            }else {
                i++;
            }
        }
        return size;
    }
}