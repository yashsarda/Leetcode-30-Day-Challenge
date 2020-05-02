/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        int dp[rows][columns];
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                dp[i][j] = 0;
            }
        }
        
        for(int i = 0; i < columns; i++) {
            dp[0][i] = (matrix[0][i] == '1');
        }
        
        for(int i = 1; i < rows; i++) {
            dp[i][0] = (matrix[i][0] == '1');
        }
        
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < columns; j++) {
                
                if(matrix[i][j] == '0') {
                    dp[i][j] = 0;
                    continue;
                }
                
                int mini = min(dp[i - 1][j], dp[i][j - 1]);
                mini = min(mini, dp[i - 1][j - 1]);
                
                dp[i][j] = mini + 1;
            }
        }
        
        int answer = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                answer = max(answer, dp[i][j]);
            }
        }
        return (answer * answer);
    }
};