/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
 The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room
 and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below,
 he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms;
 other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
 */
 class Solution {
 public:
     int calculateMinimumHP(vector<vector<int>>& A) {
         int rows = A.size();
         int col = A[0].size();

         int dp[rows + 5][col + 5];
         memset(dp,0,sizeof(dp));

         dp[rows - 1][col - 1] = (A[rows - 1][col - 1] < 0 ? abs(A[rows - 1][col - 1]) + 1 : 1);

         for(int i = col - 2; i >= 0; i--){
             dp[rows - 1][i] = A[rows - 1][i] - dp[rows - 1][i + 1] < 0 ? dp[rows - 1][i + 1] - A[rows - 1][i] : 1;
         }

         for(int i = rows - 2; i >= 0; i--){
             dp[i][col-1] = A[i][col-1] - dp[i + 1][col-1] < 0 ? dp[i + 1][col - 1] - A[i][col - 1] : 1;
         }

         for(int i = rows - 2; i >= 0; i--){
             for(int j = col-2; j >= 0; j--){
                 int val1 = A[i][j] - dp[i + 1][j];
                 int val2 = A[i][j] - dp[i][j + 1];
                 int t = max(val1,val2);
                 if(t < 0)
                     dp[i][j] = abs(t);
                 else
                     dp[i][j] = 1;
             }
         }
         return dp[0][0];

     }
 };
