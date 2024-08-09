class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> spiralMatrix {};
        int matrixSize = rows * cols , sizeCounter = 1;
        int top = 1, bottom = 2, left = 2, right = 1; 

        spiralMatrix.push_back({rStart, cStart});
        while( sizeCounter < matrixSize )
        {
            for( int  i = 0 ; i < top && sizeCounter < matrixSize ; ++i )
            {
                cStart++;
                if( cStart >= 0 && cStart < cols && rStart >= 0 && rStart < rows )
                {
                    sizeCounter++;
                    spiralMatrix.push_back({rStart, cStart});     
                }                    
            }
            for( int  i = 0 ; i < right && sizeCounter < matrixSize ; ++i )
            {
                rStart++;
                if( cStart >= 0 && cStart < cols && rStart >= 0 && rStart < rows )
                {
                    sizeCounter++;
                    spiralMatrix.push_back({rStart, cStart});     
                }                    
            }
            for( int  i = 0 ; i < bottom && sizeCounter < matrixSize ; ++i )
            {
                cStart--;
                if( cStart >= 0 && cStart < cols && rStart >= 0 && rStart < rows )
                {
                    sizeCounter++;
                    spiralMatrix.push_back({rStart, cStart});     
                }                    
            } 
            for( int  i = 0 ; i < left && sizeCounter < matrixSize ; ++i )
            {
                rStart--;
                if( cStart >= 0 && cStart < cols && rStart >= 0 && rStart < rows )
                {
                    sizeCounter++;
                    spiralMatrix.push_back({rStart, cStart});     
                }                    
            }                       
            top += 2;
            right += 2;
            bottom += 2;
            left += 2;
        }
        return spiralMatrix;
    }
};