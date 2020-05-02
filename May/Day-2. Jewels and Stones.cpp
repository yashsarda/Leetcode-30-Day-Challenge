/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have. 
 Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, s
o "a" is considered a different type of stone from "A".
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jlen = J.size();
        int slen = S.size();
        
        vector<bool> freq_small(26, false), freq_large(26, false);
        
        for(char c: J) {
            if(c >= 'a' && c <= 'z')
                freq_small[c - 'a'] = true;
            else
                freq_large[c - 'A'] = true;
        }
        int answer = 0;
        for(char c : S) {
            if(c >= 'a' && c <= 'z')
                answer += freq_small[c - 'a'];
            else
                answer += freq_large[c - 'A'];
        }
        return answer;
    }
};