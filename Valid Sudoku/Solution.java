class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<Character>[] rowSetArr = new HashSet[9];
        Set<Character>[] colSetArr = new HashSet[9];
        Set<Character>[] gridSetArr = new HashSet[9];

        for (int i = 0; i < 9; ++i) {
            rowSetArr[i] = new HashSet<>();
            colSetArr[i] = new HashSet<>();
            gridSetArr[i] = new HashSet<>();
        }

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char cell = board[i][j];

                if (cell == '.') continue;

                int gridNo = (i / 3) * 3 + (j / 3);
                if (rowSetArr[i].contains(cell) ||
                    colSetArr[j].contains(cell) ||
                    gridSetArr[gridNo].contains(cell)
                ) {
                    return false;
                }

                rowSetArr[i].add(cell);
                colSetArr[j].add(cell);
                gridSetArr[gridNo].add(cell);
            }
        }
        return true;
    }
}