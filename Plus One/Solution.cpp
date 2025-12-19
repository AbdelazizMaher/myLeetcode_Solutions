class Solution {
    fun plusOne(digits: IntArray): IntArray {
        var digitsList = digits.toMutableList()

        val lastNine = digitsList.indexOfLast { it != 9 }

        return when (lastNine) {
            -1 -> IntArray(digits.size + 1) { if (it == 0) 1 else 0 }
            else -> digitsList
                .mapIndexed { index, value ->
                    when {
                        index == lastNine -> value + 1
                        index < lastNine -> value
                        else -> 0
                    }       
                }.toIntArray()
        }
    }
}