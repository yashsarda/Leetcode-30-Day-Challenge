/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
 */
 class Solution {
     int rows, columns;
     boolean isSafe(int x, int y)
     {
         return !(x < 0 || x >= rows || y < 0 || y >= columns);
     }
     void dfs(char[][] board, int x, int y, boolean[][] visited)
     {
         visited[x][y] = true;
         board[x][y] = 'Y';

         int[] xd = {1, -1, 0, 0};
         int[] yd = {0, 0, 1, -1};

         for(int i = 0; i < 4; i++) {
             int new_x = x + xd[i];
             int new_y = y + yd[i];

             if(isSafe(new_x, new_y) && !visited[new_x][new_y] && board[new_x][new_y] == 'O')
                 dfs(board, new_x, new_y, visited);
         }
     }
     public void solve(char[][] board) {
         rows = board.length;
         if(rows == 0)
             return;
         columns = board[0].length;

         boolean[][] visited = new boolean[rows][columns];

         for(int i = 0; i < rows; i++)
             Arrays.fill(visited[i], false);

         for(int i = 0; i < columns; i++) {
             if(board[0][i] == 'O')
                 dfs(board, 0, i, visited);
             if(board[rows - 1][i] == 'O')
                 dfs(board, rows - 1, i, visited);
         }

         for(int i = 0; i < rows; i++) {
             if(board[i][0] == 'O')
                 dfs(board, i, 0, visited);
             if(board[i][columns - 1] == 'O')
                 dfs(board, i, columns - 1, visited);
         }

         for(int i = 0; i < rows; i++) {
             for(int j = 0; j < columns; j++) {
                 if(board[i][j] == 'Y')
                     board[i][j] = 'O';
                 else if(board[i][j] == 'O')
                     board[i][j] = 'X';
             }
         }
     }
 }
