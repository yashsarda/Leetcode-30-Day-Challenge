/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/
/*
Dynamic Programming on 2 string

dp(i, j) = minimum number of operations required to convert word1[0...i] to word[0..j]


If word1[i] == word2[j], then dp(i, j) = dp(i - 1, j - 1)
if not then

Insert
ABA ABC -> ABAC, ABC -> ABA, AB -> dp(i, j - 1)
ABC AB -> AB, AB -> dp(i - 1, j)
ABC, ABD -> AB, AB -> dp(i - 1, j - 1)

*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();


        // First string in rows, and second string in columns
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, INT_MAX));

        // Both strings are empty, then no operations required
        dp[0][0] = 0;

        // If the first string is empty and second is not empty

        for(int i = 0; i < n; i++) {
            dp[0][i + 1] = (i + 1);
        }

        // If the second is empty and first is not
        for(int i = 0; i < m; i++) {
            dp[i + 1][0] = (i + 1);
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = 1 + min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};
