/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and 
is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
class Solution {
    boolean[][] visited;
    int rows, columns;
    boolean isSafe(int x, int y)
    {
        return !(x < 0 || x >= rows || y < 0 || y >= columns);
    }
    void dfs(char[][] grid, int x, int y)
    {
        visited[x][y] = true;
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        
        for(int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
           // System.out.println(x + " " + y);
            if(isSafe(new_x, new_y) && grid[new_x][new_y] == '1' && !visited[new_x][new_y]) {
                dfs(grid, new_x, new_y);
            }
        }
    }
    public int numIslands(char[][] grid) {
        if(grid.length == 0)
            return 0;
        
        rows = grid.length;
        columns = grid[0].length;
        
        int answer = 0;
        visited = new boolean[rows][columns];
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j);
                    answer++;
                }
            }
        }
        
        
        return answer;
    }
}