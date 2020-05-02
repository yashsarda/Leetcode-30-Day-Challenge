/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
/*
Solution will use 2 stack
One stack for maintaining the minimum uptil current index
Second stack to push and pop elements


-2 0 1 -3 -> Stack 1 
-2 -2 -2 -3 -> Stack 2 (Minimum stack)

*/
class MinStack {
public:
    vector<pair<int,int> > s1;
    MinStack() {
        s1.clear();
    }
    
    void push(int x) {
        if(s1.empty()) {
            s1.push_back({x,x});
            return;
        }
        pair<int,int> t = s1.back();
        if(x <= t.second) {
            s1.push_back({x, x});
        }
        else {
            s1.push_back({x, t.second});
        }
        
    }
    
    void pop() {
        if(s1.empty())
            return;
        s1.pop_back();
    }
    
    int top() {
        return s1.back().first;
    }
    
    int getMin() {
        return s1.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */