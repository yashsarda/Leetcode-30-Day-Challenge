/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
*/

/*
Push digits in increasing order in the stack.
As soon as we find a digit which is in decreasing order, pop the top of the stack

a -> b -> c -> d
Suppose c > b > a
Suppose d < c
Remove d, decrease k
If b is also < d, then remove b, decrease k

10024532 -> 1002432 -> 100232 -> 10022

*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == 0)
            return num;
        stack<int> s;
        for(int i = 0; i < n; i++) {
            int number = num[i] - '0';
            while(!s.empty() && s.top() > number && k > 0) {
                    s.pop();
                    k -= 1;
            }
            s.push(number);
        }
        while(!s.empty() && k > 0) {
            s.pop();
            k -= 1;
        }
        string answer = "";
        while(!s.empty()) {
            answer += (char)(s.top() + '0');
            s.pop();
        }
        // Remove the leading zeros
        while(answer.size() > 0 && answer.back() == '0')
            answer.pop_back();
        reverse(answer.begin(), answer.end());
        if(answer == "")
            return "0";
        return answer;
    }
};