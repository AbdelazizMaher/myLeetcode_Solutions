class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for( int i = 0 ; i <= rows - 3 ; ++i ) 
        {
            for( int j = 0 ; j <= cols - 3 ; ++j ) 
            {
                if( isMagicSquare(grid, i, j) )
                    count++;
            }
        }
        return count;       
    }

    bool isMagicSquare(const vector<vector<int>>& grid, int row, int col) {
        vector<int> magicSquare;
        for( int i = 0 ; i < 3 ; ++i ) 
        { 
            for( int j = 0 ; j < 3 ; ++j ) 
                magicSquare.push_back(grid[row + i][col + j]);
        }
        
        if( all_of(magicSquare.begin(), magicSquare.end(), [](int value) {
            return value >= 1 && value <= 9;
        }) )
        
        sort(magicSquare.begin(), magicSquare.end());
        if( !equal(magicSquare.begin(), magicSquare.end(), vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}.begin()) ) 
            return false;
        
        int targetSum = accumulate(grid[row].begin() + col, grid[row].begin() + col + 3, 0);
        
        for( int i = 0 ; i < 3 ; ++i ) 
        {
            int rowSum = accumulate(grid[row + i].begin() + col, grid[row + i].begin() + col + 3, 0);
            if( rowSum != targetSum ) 
                return false;
        }
        
        for( int j = 0 ; j < 3 ; ++j ) 
        {
            int colSum = grid[row][col + j] + grid[row + 1][col + j] + grid[row + 2][col + j];
            if (colSum != targetSum) return false;
        }
        
        int diagonal1Sum = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diagonal2Sum = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
        
        if( diagonal1Sum != targetSum || diagonal2Sum != targetSum ) 
            return false;
        
        return true;
    }
};