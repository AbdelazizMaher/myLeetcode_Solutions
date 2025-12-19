class Solution {
    fun lengthOfLastWord(s: String): Int {
        return s
            .trim()
            .reversed()
            .takeWhile { it != ' ' }
            .count()
    }
}