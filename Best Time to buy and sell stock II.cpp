/*
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        if(n <= 1)
            return 0;
        int answer = 0;
        int index = 1;
        int min_value = prices[0];
        int max_value = INT_MIN;
        
        while(index < n) {
            while(index < n && prices[index] <= prices[index - 1]) {
                min_value = min(min_value, prices[index]);
                index++;
            }
            while(index < n && prices[index] >= prices[index - 1]) {
                max_value = max(max_value, prices[index]);
                index++;
            }
            if(max_value != INT_MIN && min_value != INT_MAX)
                answer += max_value - min_value;
            max_value = INT_MIN;
            min_value = INT_MAX;
        }
        return answer;
    }
};