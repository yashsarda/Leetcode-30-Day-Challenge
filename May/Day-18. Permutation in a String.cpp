/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
In other words, one of the first string's permutations is the substring of the second string.
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();
        
        vector<bool> isPresent(26, false);
        int counter = 0;
        vector<int> freq(26, 0);
    
        
        for(char c : s1) {
            freq[c - 'a']++;
            isPresent[c - 'a'] = true;
            counter += (freq[c - 'a'] == 1);
        }
        
        int left = 0; 
        int right = 0;
        
        // Use sliding window algorithm
        while(right < n) {
            
            // Currently processing s[right]
            char c = s2[right];
            if(isPresent[c - 'a']) {
                freq[c - 'a'] -= 1;
                if(freq[c - 'a'] == 0)
                        counter--;
            }

            while(counter == 0 && left <= right) {
                if(right - left + 1 == m)
                    return true;
                if(isPresent[s2[left] - 'a']) {
                    freq[s2[left] - 'a']++;
                    if(freq[s2[left] - 'a'] > 0)
                        counter++;
                }
                left++;
            }
            right++;
        }
        return false;
    }
};