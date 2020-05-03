/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the 
ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> counter(26, 0);
        
        for(char c : magazine)
            counter[c - 'a']++;
        
        for(char c : ransomNote) {
            if(counter[c - 'a'] > 0)
                counter[c - 'a']--;
            else
                return false;
        }
        return true;
    }
};