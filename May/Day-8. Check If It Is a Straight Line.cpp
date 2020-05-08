/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
*/
class Solution {
    bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    bool checkStraightLine(vector<vector<int>>& A) {
        int rows = A.size();
        sort(A.begin(), A.end());
        int change_x = A[1][0] - A[0][0];
        int change_y = A[1][1] - A[0][1];
        
        int g = __gcd(change_x, change_y);
        change_x /= g;
        change_y /= g;
        
        for(int i = 2; i < rows; i++) {
            int xd = A[i][0] - A[i - 1][0];
            int yd = A[i][1] - A[i - 1][1];
            g = __gcd(xd, yd);
            
            if(xd / g != change_x || yd / g != change_y)
                return false;
        }
        return true;
    }
};