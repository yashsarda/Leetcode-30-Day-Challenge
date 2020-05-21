/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        vector<vector<int> > prefix(rows, vector<int>(columns, 0));
        
        for(int i = 0; i < rows; i++) {
            prefix[i][0] = matrix[i][0];
        }
        
        for(int i = 0; i < rows; i++) {
            for(int j = 1; j < columns; j++) {
                prefix[i][j] = prefix[i][j - 1] + matrix[i][j];
            }
        }
        
        for(int i = 1; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                prefix[i][j] += prefix[i - 1][j];
            }
        }
        
        int answer = 0;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                
                int x = i;
                int y = j;
    
                while(x >= 0 && y >= 0) {
                    int sum = prefix[i][j];
                    
                    if(x - 1 >= 0)
                        sum -= prefix[x - 1][j];
                    if(y - 1 >= 0)
                        sum -= prefix[i][y - 1];
                    if(x - 1 >= 0 && y - 1 >= 0)
                        sum += prefix[x - 1][y - 1];
                    
                    int r = (i - x + 1);
                    int c = (j - y + 1);
                    
                    answer += (r * r == sum && c * c == sum);
                    
                    x--;
                    y--;
                }
            }
        }
        return answer;
    }
};