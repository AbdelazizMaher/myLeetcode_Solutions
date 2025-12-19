class Solution {
    public String longestPalindrome(String s) {
        String res = "";

        if (s.length() <= 1) return s;

       for (int i = 0; i < s.length(); ++i) {
            for (int j = i + 1; j <= s.length(); j++) {
                String str = s.substring(i,j);
                if (isPalindrome(str) && str.length() > res.length()) {
                    res = str;
                }
            }
       }
       return res; 
    }

    private Boolean isPalindrome(String pal) {
        int start = 0;
        int end = pal.length() - 1;
        while (start < end) {
            if (pal.charAt(start++) != pal.charAt(end--))
                return false;
        }
        return true;
    }
}