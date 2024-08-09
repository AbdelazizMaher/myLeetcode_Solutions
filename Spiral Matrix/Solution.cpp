class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0, right = cols - 1 , bottom = rows - 1, left = 0;
        int direction = 0;

        vector<int> spiralMatrix {};
        while( top <= bottom && left <= right )
        {
            if( direction == 0 )
            {
                for( int  i = left ; i <= right ; ++i )
                    spiralMatrix.push_back(matrix[top][i]);
                top++;
                direction = 1;
            }
            else if( direction == 1 ) 
            {
                for( int i = top ; i <= bottom; ++i ) 
                    spiralMatrix.push_back(matrix[i][right]);
                right--;
                direction = 2;
            }
            else if( direction == 2 ) 
            {
                for( int i = right ; i >= left ; --i )
                    spiralMatrix.push_back(matrix[bottom][i]);
                bottom--;
                direction = 3;
            }
            else 
            {
                for( int i = bottom ; i >= top ; --i ) 
                    spiralMatrix.push_back(matrix[i][left]);
                left++;
                direction = 0;
            }            
        }
        return spiralMatrix;
    }
};