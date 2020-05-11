/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned 
pixels with the newColor.

At the end, return the modified image.
*/
class Solution {
    int value;
    int rows, columns;
public:
    bool isSafe(int x, int y)
    {
        return !(x < 0 || x >= rows || y < 0 || y >= columns);
    }
    void dfs(int x, int y, vector<vector<int> >& image, vector<vector<bool> >& visited, int newColor)
    {
        visited[x][y] = true;
        image[x][y] = newColor;
        
        int xd[] = {1, -1, 0, 0};
        int yd[] = {0, 0, 1, -1};
        
        for(int i = 0; i < 4; i++) {
            int new_x = x + xd[i];
            int new_y = y + yd[i];
            
            if(isSafe(new_x, new_y) && !visited[new_x][new_y] && image[new_x][new_y] == value) {
                dfs(new_x, new_y, image, visited, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        rows = image.size();
        columns = image[0].size();
        
        value = image[sr][sc];
        vector<vector<bool> > visited(rows, vector<bool>(columns, false));
        dfs(sr, sc, image, visited, newColor);
        
        return image;
    }
};