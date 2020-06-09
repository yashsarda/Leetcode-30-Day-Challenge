/*
Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none)
of the characters without
disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();

        int i = 0, j = 0;

        while(i < slen && j < tlen) {
            if(s[i] == t[j])
                i++;
            j++;
        }
        return (i == slen);
    }
};
