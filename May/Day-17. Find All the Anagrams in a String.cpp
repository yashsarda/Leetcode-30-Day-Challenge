/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<int> answer;
        vector<bool> isPresent(26, false);
        int counter = 0;
        vector<int> freq(26, 0);
        
        // count the frequencies of the characters in the p
        // Note the characters which are present in the string p
        for(char c : p) {
            freq[c - 'a']++;
            isPresent[c - 'a'] = true;
            counter += (freq[c - 'a'] == 1);
        }
        
        // counter denotes the count of distinct characters in string p
        int left = 0; 
        int right = 0;
        
        // Use sliding window algorithm
        while(right < n) {
            
            // Currently processing s[right]
            char c = s[right];
            if(isPresent[c - 'a']) {
                freq[c - 'a'] -= 1;
                
                // We have found required freqeuncy of c which is present in p, so decrease counter
                if(freq[c - 'a'] == 0)
                        counter--;
            }

            // Used the while loop because it's possible that there will be lot of character at
            // the start of the string which might not be present in p
            while(counter == 0 && left <= right) {
                // Length of the substring s[left, right] = length of p
                if(right - left + 1 == m)
                    answer.push_back(left);
                if(isPresent[s[left] - 'a']) {
                    freq[s[left] - 'a']++;
                    // Only increase counter if there are more number than required
                    if(freq[s[left] - 'a'] > 0)
                        counter++;
                }
                left++;
            }
            right++;
        }
        return answer;
    }
};