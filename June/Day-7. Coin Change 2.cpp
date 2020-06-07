/*
You are given coins of different denominations and a total amount of money.
Write a function to compute the number of combinations that make up that amount.
You may assume that you have infinite number of each kind of coin.
*/
// ways[i] = number of ways to make an amount of i using coins
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<int> ways(amount + 5, 0);
        sort(coins.begin(), coins.end());
        ways[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = coins[i]; j <= amount; j++) {
                ways[j] += ways[j - coins[i]];
            }
        }
        return ways[amount];
    }
};
