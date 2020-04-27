/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
    public int minPathSum(int[][] grid) {
        int rows = grid.length;
        int columns = grid[0].length;
        
        if(rows == 0)
            return 0;
        
        int[][] dp = new int[rows][columns];
        dp[0][0] = grid[0][0];
        
        for(int i = 1; i < rows; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        
        for(int i = 1; i < columns; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < columns; j++) {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        
        return dp[rows - 1][columns - 1];
    }
}