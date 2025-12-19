class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder sb = new StringBuilder(s.toLowerCase());
        for (int i = 0; i < sb.length(); ++i) {
            if (!Character.isLetterOrDigit(sb.charAt(i))) {
                sb.deleteCharAt(i);
                i--;
            }
        }
        if (sb.toString().equals(sb.reverse().toString())) {
            return true;
        }
        return false;
    }
}