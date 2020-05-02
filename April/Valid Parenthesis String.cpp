/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. 
We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
*/


class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        if(n == 0)
            return true;
        if(n == 1)
            return s[0] == '*';
        
        stack<int> st;
        deque<int> dq;
        vector<int> closing_index;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()) {
                    closing_index.push_back(i);
                }
                else {
                    st.pop();
                }
            }
            else {
                dq.push_back(i);
            }
        }
        
        while(!st.empty()) {
            int index = st.top();
            if(dq.empty() || dq.back() < index)
                return false;
            dq.pop_back();
            st.pop();
        }
        if(closing_index.empty())
            return true;
        int index = closing_index.back();
        while(!dq.empty() && dq.back() > index)
            dq.pop_back();
        if(dq.empty())
            return false;
        
        for(int i = closing_index.size() - 1 ; i >= 0; i--) {
            int ind = closing_index[i]; 
            if(dq.empty() || dq.back() > ind)
                return false;
            dq.pop_back();
        }
        return true;
        
    }
};