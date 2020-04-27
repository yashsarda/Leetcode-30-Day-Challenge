/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.
*/
// O(N) time and O(N) space
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        string new_s = "";
        string new_t = "";
        
        for(char c: S) {
            if(c == '#') {
                if(new_s != "")
                    new_s.pop_back();
            }
            else {
                new_s += c;
            }
        }
        
        for(char c: T) {
            if(c == '#') {
                if(new_t != "")
                    new_t.pop_back();
            }
            else {
                new_t += c;
            }
        }
        return new_s == new_t;
        
    }
};
