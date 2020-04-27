/*
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        
        priority_queue<int> pq;
        
        for(int stone : stones) {
            pq.push(stone);
        }
        
        while(pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            
            if(x == y)
                continue;
            
            pq.push(y - x);
        }
        
        if(pq.empty())
            return 0;
        return pq.top();
    }
};