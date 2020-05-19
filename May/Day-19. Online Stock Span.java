/*
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) 
for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
*/

// No idea why this same code in CPP did not work
class StockSpanner {

    List<Integer> weight;
    List<Integer> counter;
    public StockSpanner() {
        weight = new ArrayList<>();
        counter = new ArrayList<>();
    }
    
    public int next(int price) {
        int answer = 1;
        while(!weight.isEmpty() && price >= weight.get(weight.size() - 1)) {
            answer += counter.get(counter.size() - 1);
            weight.remove(weight.size() - 1);
            counter.remove(counter.size() - 1);
        }
        weight.add(price);
        counter.add(answer);
        return answer;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */